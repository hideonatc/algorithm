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
	data *ptr;
	head=(data*)malloc(sizeof(data));
	ptr=head;
	ptr->next=ptr;
	while(printf("add data (a) print data (d) quit (q)\n")){
		char in;
		cin>>in;
		if(in=='a'){
			scanf("%s %d",ptr->name,&ptr->age);
			data *nw;
			nw=(data*)malloc(sizeof(data));
			ptr->next=nw;
			nw->next=head;
			ptr=nw;
		}
		else if(in=='p'){
			data *now;
			now=head;
			while(now->next!=head){
				printf("name:%s age:%d\n",now->name,now->age);
				now=now->next;
			}
		}
		else if(in=='q')
			return 0;
		else
			printf("Invalid command\n");
	}
}