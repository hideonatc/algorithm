#include<iostream>
#include<cmath>
using namespace std;
struct T{
	int x,y;
}pt[999];
float map[999][999];
float leng(int a,int b){
	return sqrt((pt[a].x-pt[b].x)*(pt[a].x-pt[b].x)+(pt[a].y-pt[b].y)*(pt[a].y-pt[b].y));
}
float len=1e9;
int start,e;
int ans_path[999],path[999],ans_t,n;
bool passed[999]={0};
void backtrack(int a,float l,int t){
	if(a==e){
		//printf("a==end\n");
		passed[e]=false;
		if(l<len){
			len=l;
			//printf("len=%f\n",len);
			for(int i=1;i<=t;i++)
				ans_path[i]=path[i];
			ans_t=t;
		}
		//printf("here\n");	
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!passed[i]&&map[a][i]>0){
				passed[i]=true;
				//printf("passed[%d]=true\n",i);
				path[t+1]=i;
				//printf("path[%d]=%d\n",t+1,i);
				//printf("backtrack(%d,%f,%d)\n",i,l+map[a][i],t+1);
				backtrack(i,l+map[a][i],t+1);
			}
			else{
				////printf("%d is passed or there is no road\n",i);
			}
		}
		//passed[path[t-1]]=false;
		//backtrack(path[--t],l+map[a][i]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[i][j]=-1;
	for(int i=1;i<=n;i++)
		cin>>pt[i].x>>pt[i].y;
	int r;
	cin>>r;
	for(int i=1;i<=n;i++)
		map[i][i]=0;
	for(int i=1;i<=r;i++){
		int a,b;
		cin>>a>>b;
		map[a][b]=map[b][a]=leng(a,b);
	}
	cin>>start>>e;
	path[1]=start;
	passed[start]=true;
	backtrack(start,0,1);
	for(int i=1;i<=ans_t;i++)
		cout<<ans_path[i]<<" ";
	cout<<endl;
	cout<<len<<endl;
}
//test data
/*
5
1 2
3 5
2 4
4 4
5 1
5
1 3
3 2
3 4
3 5
4 5
1 5
*/
/*
1 3 5
6.47870
*/