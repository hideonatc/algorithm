#include<iostream>
#include<cstdlib>
using namespace std;
struct data{
	char name[20];
	int age;
	data *next;
};
int main(){
	data *head;
	data *now;
	data *ptr;
	head=(data*)malloc(sizeof(data));
	ptr=head;
	ptr->next=NULL;
	while(printf("add data (a) print data (p) quit (q)\n")){
		char in;
		cin>>in;
		if(in=='a'){
			scanf("%s %d",ptr->name,&ptr->age);
			now=(data*)malloc(sizeof(data));
			ptr->next=now;
			ptr=now;
			now->next=NULL;
		}
		else if(in=='p'){
			data *vis;
			vis=head;
			while(vis->next!=NULL){
				printf("name:%s age:%d\n",vis->name,vis->age);
				vis=vis->next;
			}
		}
		else if(in=='q')
			return 0;
		else
			printf("Invalid input\n");
	}
}