#include<iostream>
using namespace std;
void gnome_sort(int a[],int t){
	for(int i=1;i<t;){
		if(i==0||a[i+1]>=a[i]){
			i++;
		}
		else{
			swap(a[i],a[i+1]);
			i--;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int num[999];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	gnome_sort(num,n);
	for(int i=1;i<=n;i++)
		cout<<num[i]<<" ";
	cout<<endl;
}