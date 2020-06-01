#include<iostream>
using namespace std;
void insertion_sort(int a[],int s){
	for(int i=2;i<=s;i++){
		int j=i-1;
		int k=i;
		while(a[k]<a[j]&&j!=0){
			swap(a[k],a[j]);
			k--;
			j--;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int arr[999]={0};
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	insertion_sort(arr,n);
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}