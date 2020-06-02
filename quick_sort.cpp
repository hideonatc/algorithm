#include<iostream>
using namespace std;
void quick_sort(int a[],int s,int e){
	if(s==e)
		s=e;
	else {
		int cp=a[e];
		int la[500],ra[500];
		int l=1,r=1;
		for(int i=s;i<e;i++){
			if(a[i]<=cp){
				la[l]=a[i];
				l++;
			}
			else {
				ra[r]=a[i];
				r++;
			}
		}
		if(l!=1){
			quick_sort(la,1,l-1);
		}
		if(r!=1){
			quick_sort(ra,1,r-1);
		}
		int li=1,ri=1;
		for(int i=s;i<s+l-1;i++){
			a[i]=la[li];
			li++;
		}
		a[s+l-1]=cp;
		for(int i=s+l;i<=e;i++){
			a[i]=ra[ri];
			ri++;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int num[999];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	quick_sort(num,1,n);
	for(int i=1;i<=n;i++)
		cout<<num[i]<<" ";
	cout<<endl;
}