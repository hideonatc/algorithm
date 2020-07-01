#include<iostream>
#include<stack>
using namespace std;
int n,m;
bool map[10][10]={0};
bool vis[10]={0};
void dfs(int s,int e){
	stack <int> st;
	st.push(s);
	vis[s]=1;
	while(!st.empty()){
		int k=st.top();
		st.pop();
		printf("visit %d\n",k);
		bool f=false;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&map[k][i]){
				if(i==e){
					printf("found %d!\n",e);
					return;
				}
				st.push(i);
				f=true;
			}
		}
		if(!f)
			printf("no way found\n");
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
	}
	dfs(1,n);
}