#include<iostream>
#include<map>
using namespace std;
int main(){
	int n;
	char a[999];
	cin>>n;
	map<char,int> m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		m[a[i]]++;
	for(auto i:m)
		printf("%c 有%d個\n",i.first,i.second);
}