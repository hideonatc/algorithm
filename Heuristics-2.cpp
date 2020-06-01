#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
	map<int,int> m1;	//<cost time,task num>
	map<int,int> m2;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		m1[a]=i;
		m2[b]=i;
	}
	map<int,int>::iterator a=m1.begin();
	map<int,int>::iterator b=m2.begin();
	vector<int> v1;
	vector<int> v2;
	int a1[999],a2[999];
	int j=1,k=1;
	bool m1_end=0,m2_end=0;
	for(int i=1;i<=2*n;i++){
		if(a->first<b->first&&!m1_end){
			v1.push_back(a->first);
			a1[j]=a->second;
			j++;
			a++;
			if(a==m1.end())
				m1_end=true;
		}
		else {
			v2.insert(v2.begin(),b->first);
			a2[n-k+1]=b->second;
			k++;
			b++;
			if(b==m2.end())
				m2_end=true;
		}
	}
	printf("machine 1 的排程:\n");
	for(int i=1;i<=n;i++)
		cout<<a1[i]<<" ";
	cout<<endl;
	printf("machine 2 的排程:\n");
	for(int i=1;i<=n;i++)
		cout<<a2[i]<<" ";
	cout<<endl;
	int ans_time=v2[n];
	for(int i=1;i<=n;i++)
		ans_time+=v1[i];
	//printf("需要時間:%d\n",ans_time);
}