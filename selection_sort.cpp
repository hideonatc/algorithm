#include<iostream>
using namespace std;
void selection_sort(int a[],int s){
	for(int i=0;i<s;i++){
		int ind,min=a[i];
		for(int j=i+1;j<s;j++){
			if(min>a[j]){
				min=a[j];
				ind=j;
			}
		}
		swap(a[ind],a[i]);
	}
}
int main(){
	int arr[999];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	selection_sort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}