#include<iostream>
using namespace std;
void merge(int a[],int start,int mid,int end){
	int l=1,r=1;
	int la[500],ra[500];
	for(int i=start;i<=mid;i++){
		la[l]=a[i];
		l++;
	}
	for(int i=mid+1;i<=end;i++){
		ra[r]=a[i];
		r++;
	}
	l=1;
	r=1;
	bool l_end=0,r_end=0;
	for(int i=start;i<=end;i++){
		if(l_end){
			a[i]=ra[r];
			r++;
		}
		else if(r_end){
			a[i]=la[l];
			l++;
		}
		else{
			if(la[l]<ra[r]){
				a[i]=la[l];
				l++;
			}
			else{
				a[i]=ra[r];
				r++;
			}
		}
		if(r==end-mid+1)
			r_end=true;
		if(l==mid-start+2)
			l_end=true;
	}
}
void merge_sort(int a[],int s,int e){
	if(e==s+1){
		if(a[s]>a[e]){
			int t=a[s];
			a[s]=a[e];
			a[e]=t;
		}
	}
	else if(e==s){
		e=s;
	}
	else {
		int l=e-s+1;
		int m=l/2;
		merge_sort(a,s,s+m-1);
		merge_sort(a,s+m,e);
		merge(a,s,s+m-1,e);
	}
}
int main(){
	int n;
	cin>>n;
	int num[999];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	merge_sort(num,1,n);
	for(int i=1;i<=n;i++)
		cout<<num[i]<<" ";
	cout<<endl;
}