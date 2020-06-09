#include<iostream>
using namespace std;
struct T{
	int xd,yd;
}rd[2000];
int map[999][999],path[999][999]={0};	//path: 1:up 2:left
int dp(int a,int b){
	for(int i=2;i<=a;i++)
		path[i][1]=1;
	for(int j=2;j<=b;j++)
		path[1][j]=2;
	for(int i=2;i<=a;i++){
		for(int j=2;j<=b;j++){
			int m=min(map[i-1][j],map[i][j-1]);
			path[i][j]=(m==map[i-1][j])?1:2;
			map[i][j]=map[i][j]+m;
		}
	}
	return map[a][b];
}
int main(){
	int x,y;
	cin>>x>>y;
	int p=x+y-1;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			cin>>map[i][j];
	cout<<dp(x,y)<<endl;
	int xx=x,yy=y;
	rd[p].xd=xx;
	rd[p].yd=yy;
	p--;
	while(path[xx][yy]){
		if(path[xx][yy]==1){
			rd[p].xd=--xx;
			rd[p].yd=yy;
			p--;
		}
		else{
			rd[p].xd=xx;
			rd[p].yd=--yy;
			p--;
		}
	}
	for(int i=1;i<=x+y-2;i++)
		printf("(%d,%d)->",rd[i].xd,rd[i].yd);
	printf("(%d,%d)\n",rd[x+y-1].xd,rd[x+y-1].yd);
}
/*test data
5 5
1 2 5 -1 3
2 1 0  3 3
2 4 -4 1 0
10 4 3 3 6
-1 -3 9 0 7
*/
/*
10
(1,1)->(1,2)->(2,2)->(2,3)->(3,3)->(3,4)->(4,4)->(5,4)->(5,5)
*/