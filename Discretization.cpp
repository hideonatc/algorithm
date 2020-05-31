#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct guest{
	int arrive,leave;
}g[999];
bool cmp(int a,int b){
	return abs(a)<abs(b);
}
int main(){
	vector<int> v;
	int p;
	cin>>p;
	for(int i=1;i<=p;i++){
		cin>>g[i].arrive>>g[i].leave;
	}
	for(int i=1;i<=p;i++){
		v.push_back(g[i].arrive);
		v.push_back(-g[i].leave);
	}
	sort(v.begin(),v.end(),cmp);
	int n=0,mx=0;
	int s,e;
	for(int i=0;i<2*p;i++){
		if(v[i]>=0){
			n++;
			if(n>=mx){
				mx=n;
				s=v[i];
			}
		}
		else{
			n--;
			if(n==mx-1)
				e=-v[i];
		}
	}
	printf("在%d ~ %d時有最多人:%d\n",s,e,mx);
}