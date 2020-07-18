#include<iostream>
using namespace std;
int map[100][100],dis[100];
bool vis[100]={0};
int dijkstra(int s,int e){
	for(int i=1;i<=e;i++)
		dis[i]=map[s][i];
	vis[s]=1;
	for(int i=2;i<=e;i++){
		int mn=1e10,p;
		for(int j=1;j<=e;j++)
			if(!vis[j]&&dis[j]<mn){
				mn=dis[j];
				p=j;
			}
		vis[p]=1;
		for(int j=1;j<=e;j++){
			if(!vis[j]&&dis[p]+map[p][j]<dis[j])
				dis[j]=dis[p]+map[p][j];
		}
	}
	return dis[e];
}
void print(int k){
	cout<<"*  ";
	for(int i=1;i<=k;i++)
		cout<<i<<"  ";
	cout<<endl;
	for(int i=1;i<=k;i++){
		cout<<i<<"  ";
		for(int j=1;j<=k;j++){
			if(map[i][j]<100)
				cout<<map[i][j]<<"  ";
			else
				cout<<"x  ";
		}
		cout<<endl;
	}
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[i][j]=1e9;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
	for(int i=1;i<=n;i++)
		map[i][i]=0;
	print(n);
	cout<<dijkstra(1,n)<<endl;
}
/*test data
8 9
1 2 2
2 4 1
2 6 4
4 6 5
1 3 5
3 6 2
3 5 7
6 7 7
5 8 6
*/ //ans:18