#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int value;
	node *l_child,*r_child;
};
int main(){
	node *root;
	node *ptr;
	root=(node*)malloc(sizeof(node));
	ptr=root;
	ptr->l_child=NULL;
	ptr->r_child=NULL;
	char in;
	system("clear");
	while(cin>>in){
		if(in=='a'){
			node *l,*r;
			l=(node*)malloc(sizeof(node));
			r=(node*)malloc(sizeof(node));
			scanf("%d %d",&l,&r);
			ptr->l_child=l;
			ptr->r_child=r;
			cin>>in;
			if(in=='l'){
				r->r_child=NULL;
				r->l_child=NULL;
				ptr=l;
				ptr->r_child=NULL;
				ptr->l_child=NULL;
			}
			else{
				l->l_child=NULL;
				l->r_child=NULL;
				ptr=r;
				ptr->r_child=NULL;
				ptr->l_child=NULL;
			}
		}
		else if(in=='l'){
			scanf("%d",&ptr->l_child);
			node *now;
			now=(node*)malloc(sizeof(node));
			ptr->r_child=NULL;
			now=ptr->l_child;
			now->l_child=NULL;
			now->r_child=NULL;
			ptr=now;
		}
		else if(in=='r'){
			scanf("%d",&ptr->r_child);
			node *now;
			now=(node*)malloc(sizeof(node));
			ptr->l_child=NULL;
			now=ptr->r_child;
			now->l_child=NULL;
			now->r_child=NULL;
			ptr=now;
		}
		else if(in=='p'){
			node *now;
			now=root;
			while(1){
				if(now==NULL){
					printf("NULL\n");
					break;
				}
				printf("%d ",now);
				cin>>in;
				if(in=='l')
					now=now->r_child;
				else
					now=now->l_child;
			}
		}
		else return 0;
	}
}