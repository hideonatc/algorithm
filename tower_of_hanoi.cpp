#include<iostream>
#include<stack>
using namespace std;
stack<int> tower[4];
stack<int> b_tower[4];
int ind=0;
void print_tower(){
	printf("-------------%d time------------\n",ind);
	ind++;
	for(int i=1;i<=3;i++)
		b_tower[i]=tower[i];
	while(!tower[1].empty()){
		cout<<"  "<<tower[1].top()<<endl;;
		tower[1].pop();
	}
	cout<<"00000"<<endl<<endl;
	while(!tower[2].empty()){
		cout<<"  "<<tower[2].top()<<endl;
		tower[2].pop();
	}
	cout<<"00000"<<endl<<endl;
	while(!tower[3].empty()){
		cout<<"  "<<tower[3].top()<<endl;
		tower[3].pop();
	}
	cout<<"00000"<<endl<<endl;
	for(int i=1;i<=3;i++)
		tower[i]=b_tower[i];
}
void move(int t,int f,int c){
	int r=6-f-c;
	if(t==1){
		tower[f].pop();
		tower[c].push(1);
		print_tower();
	}
	else{
		move(t-1,f,r);
		if(tower[f].top()==t&&tower[r].top()==1){
			tower[f].pop();
			tower[c].push(t);
			print_tower();
			move(t-1,r,c);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=n;i>0;i--)
		tower[1].push(i);
	print_tower();
	move(n,1,3);
}