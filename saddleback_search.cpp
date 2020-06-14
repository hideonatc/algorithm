#include<iostream>
using namespace std;
int num[5][5]={{1,3,7,9,13},{2,4,8,10,14},{5,6,9,12,15},{7,12,13,15,19},{11,13,16,18,20}};//sorted matrix
void saddleback_search(int a,int b,int f){
	int xn=0,yn=b-1;
	while(xn<a&&yn>=0){
		if(num[xn][yn]<f)
			xn++;
		else if(num[xn][yn]>f)
			yn--;
		else{
			printf("(%d,%d) ",xn,yn);
			xn++;
		}
	}
}
int main(){
	int x=5,y=5;//5*5 matrix
	int find=15;
	saddleback_search(x,y,find);
	cout<<endl;
}