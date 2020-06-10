//not totally the same
#include<iostream>
#include<time.h>
using namespace std;
bool ok[999]={0};
void sleep_sort(int a[],int t,int m){
	ios_base::sync_with_stdio(false);
	clock_t start=clock();
	clock_t now=clock();
	while((now-start)/20<=m){
		now=clock();
		for(int i=1;i<=t;i++)
			if(!ok[i]&&a[i]==(now-start)/20){
				cout<<a[i]<<" ";
				ok[i]=true;
			}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	int max=-1;
	int num[999];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(max<num[i])
			max=num[i];
	}
	sleep_sort(num,n,max);
	cout<<endl;
}