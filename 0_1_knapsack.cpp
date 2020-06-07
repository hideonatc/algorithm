#include<iostream>
using namespace std;
int MAX_W,MAX_P=-1;
int weight[999],price[999];
bool ans[999]={0},ans_fn[999]={0};
void backtrack(int n,int t,int p,int w){
	if(t==n+1){
		if(p>MAX_P){
			MAX_P=p;
			for(int i=1;i<=n;i++)
				ans[i]=ans_fn[i];
		}
	}
	else{
		if(w+weight[t]<=MAX_W){
			w+=weight[t];
			p+=price[t];
			ans_fn[t]=true;
			backtrack(n,t+1,p,w);
		}
		ans_fn[t]=false;
		backtrack(n,t+1,p,w);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>weight[i]>>price[i];
	cin>>MAX_W;
	backtrack(n,1,0,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	cout<<MAX_P<<endl;
}