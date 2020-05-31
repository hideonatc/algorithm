#include<iostream>
using namespace std;
int c[10]={0};
void counting_sort(int a[],int t){
	for(int i=0;i<t;i++)
		c[a[i]]++;
	int p=0;
	for(int i=0;i<t;){
		if(c[p]>0){
			a[i]=p;
			c[p]--;
			i++;
		}
		else 
			p++;
	}
}
int main(){
	string s;
	cin>>s;
	int l=s.length();
	int arr[999];
	for(int i=0;i<l;i++){
		arr[i]=s[i]-'0';
	}
	counting_sort(arr,l);
	for(int i=0;i<l;i++)
		cout<<arr[i];
	cout<<endl;
}