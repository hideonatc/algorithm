#include<iostream>
#define ull unsigned long long
using namespace std;
struct T{
	int c,r;
	ull s;
};
T input[999],mat[999][999];
ull dp(int a){
	for(int i=1;i+1<=a;i++){
		mat[i][i+1].c=input[i+1].c;
		mat[i][i+1].r=input[i].r;
		mat[i][i+1].s=input[i+1].c*input[i].r*input[i].c;
		//printf("mat[%d][%d] r=%d c=%d\n",i,i+1,input[i].r,input[i+1].c);
		//printf("mat[%d][%d].s=%d*%d*%d\n",i,i+1,input[i].r,input[i].c,input[i+1].c);
	}
	for(int j=2;j<=a-1;j++){
		for(int k=1;k+j<=a;k++){
			ull sleft=mat[k][k+j-1].s;
			int cleft=mat[k][k+j-1].c,rleft=mat[k][k+j-1].r;
			//printf("cleft : %d,rleft : %d\n",cleft,rleft);
			ull sdown=mat[k+1][k+j].s;
			int cdown=mat[k+1][k+j].c,rdown=mat[k+1][k+j].r;
			//printf("cdown : %d,rdown : %d\n",cdown,rdown);
			//printf("sleft : %llu,sdown : %llu\n",sleft,sdown);
			ull left=sleft+(rleft*input[k+j].c*cleft);
			ull down=sdown+(input[k].r*cdown*rdown);
			//printf("left : %llu,down : %llu\n",left,down);
			if(left<down){
				mat[k][k+j].s=left;
				//printf("(%d,%d)*%d\n",k,k+j-1,k+j);
			}
			else{
				mat[k][k+j].s=down;
				//printf("%d*(%d,%d)\n",k,k+1,k+j);
			}
			mat[k][k+j].r=input[k].r;
			mat[k][k+j].c=input[k+j].c;
		}
	}
	return mat[1][a].s;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>input[i].r>>input[i].c;
		input[i].s=-1;
	}
	cout<<dp(n)<<endl;
}
/*test data
4
10 20 
20 30 
30 40 
40 30 
*/
/*30000*/