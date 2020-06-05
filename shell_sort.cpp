#include<iostream>
using namespace std;
void insertion_sort(int a[],int s){
	//printf("insertion sort,s=%d\n",s);
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
void shell_sort(int a[],int t,int l){
	//printf("shell sort,t=%d\n",t);
	int k=t;
	t/=2;
	if(t==1)
		insertion_sort(a,l);
	else{
		int arr[999];
		for(int i=1;i<=t;i++){
			int ind=1;
			for(int j=i;j<=l;j+=t){
				arr[ind]=a[j];
				ind++;
			}
			insertion_sort(arr,ind-1);
			ind=1;
			for(int j=i;j<=l;j+=t){
				a[j]=arr[ind];
				ind++;
			}
			/*for(int j=1;j<=l;j++)
				cout<<a[j]<<" ";
			cout<<endl;*/
		}
		shell_sort(a,t,l);
	}
}
int main(){
	int n;
	cin>>n;
	int num[999];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	shell_sort(num,n,n);
	for(int i=1;i<=n;i++)
		cout<<num[i]<<" ";
	cout<<endl;
}