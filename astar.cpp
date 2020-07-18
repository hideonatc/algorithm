//seems unfinished(?)
#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
struct nod{
	int x,y;
};
int dir[8][3]={{-1,-1,15},{-1,0,10},{-1,1,15},{0,-1,10},{0,1,10},{1,-1,15},{1,0,10},{1,1,15}};
struct data{
	int val;
	int cd;
	int h,f;
	nod f_nd;
}map[10][10];
bool cap(nod n){
	if(n.x>=10||n.x<0||n.y>=10||n.y<0)
		return 0;
	if(map[n.x][n.y].val==0||map[n.x][n.y].cd==2)
		return 0;
	return 1;
}
int main(){
	/*set up*/
	nod start,end;
	start.x=3;
	start.y=3;
	end.x=3;
	end.y=7;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			map[i][j].val=1;
			map[i][j].cd=0;
			map[i][j].h=(abs(i-end.x)+abs(j-end.y))*10;
		}
	for(int i=2;i<=4;i++)
		map[i][5].val=0;
	/*end of set up*/
	nod th=start;
	cout<<"here"<<endl;
	while(th.x!=end.x||th.y!=end.y){
		printf("th=(%d,%d)\n",th.x,th.y);
		int mnf=int(1e9);
		nod next;
		for(int i=0;i<8;i++){
			nod now;
			now.x=th.x+dir[i][0];
			now.y=th.y+dir[i][1];
			if(!cap(now))
				continue;
			if(map[now.x][now.y].cd==0){
				map[now.x][now.y].cd=1;
				map[now.x][now.y].f_nd=th;
				map[now.x][now.y].f=map[now.x][now.y].h+dir[i][2];
			}
			else{
				if(map[now.x][now.y].f>map[now.x][now.y].h+dir[i][2]){
					map[now.x][now.y].f=map[now.x][now.y].h+dir[i][2];
					map[now.x][now.y].f_nd=th;
				}
			}
			if(mnf>map[now.x][now.y].f){
				next.x=now.x;
				next.y=now.y;
				mnf=map[now.x][now.y].f;
			}
		}
		map[th.x][th.y].cd=2;
		th=next;
	}
	nod b=end;
	stack<nod> bpath;
	while(map[b.x][b.y].f_nd.x!=start.x&&map[b.x][b.y].f_nd.y!=start.y){
		bpath.push(b);
		b=map[b.x][b.y].f_nd;
	}
	bpath.push(b);
	bpath.push(map[b.x][b.y].f_nd);
	while(!bpath.empty()){
		printf("(%d,%d) ",bpath.top().x,bpath.top().y);
		bpath.pop();
	}
	cout<<endl;
}