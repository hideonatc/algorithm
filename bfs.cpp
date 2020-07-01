#include<iostream>
#include<queue>
using namespace std;
int map[10][10]={0};
int vis[10]={0};
int n,m;
void bfs(int s,int e){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		printf("leave node %d\n",k);
		bool f=false;
		for(int i=1;i<=n;i++){
			if(map[k][i]&&!vis[i]){
				if(i==e){
					printf("found node %d!\n",i);
					return;
				}
				vis[i]=true;
				f=true;
				q.push(i);
				printf("visit node %d\n",i);
			}
		}
		if(!f)
			printf("no node found\n");
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
	}
	bfs(1,n);
}