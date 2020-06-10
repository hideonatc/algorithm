#include<iostream>
using namespace std;
void bubble_sort(int a[],int t){
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t-i;j++){
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}
int main(){
	int n;
	cin>>n;
	int num[999];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	bubble_sort(num,n);
	for(int i=1;i<=n;i++)
		cout<<num[i]<<" ";
	cout<<endl;
}