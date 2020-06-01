#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int ,int> m;	//<deadline,cost time>
	map<int ,int> m2;
	for(int i=1;i<=n;i++){
		int d,c;
		cin>>c>>d;
		m[d]=c;
	}
	int t=0,tsk=0;
	for(auto i:m){
		m2[i.second]=i.first;
		t+=i.second;
		tsk++;
		if(t>i.first){
			int k;
			for(auto j:m2)
				k=j.first;
			t-=k;
			m2.erase(k);
			tsk--;
		}
	}
	printf("最少能在%d時間內完成最多%d樣工作",t,tsk);
	cout<<endl;
}