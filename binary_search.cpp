#include<iostream>
using namespace std;
void binary_search(int a[],int s,int e,int t){
	int m=(s+e)/2;
	if(a[m]>t)
		binary_search(a,s,m-1,t);
	else if(a[m]<t)
		binary_search(a,m+1,e,t);
	else
		printf("%d is at position %d\n",t,m);
}
int main(){
	int n;
	cin>>n;
	int num[999];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	int f;
	cin>>f;
	binary_search(num,1,n,f);
}