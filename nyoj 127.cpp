#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
const int mo = 10003;
int qpow(int x,int y)
{
	if(y==0) return 1;
	if(y%2==0) return (qpow(x,y/2) * qpow(x,y/2)) % mo;
	else return (x * qpow(x,y/2) * qpow(x,y/2)) % mo;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==2) printf("1\n");
		else printf("%d\n",(qpow(n,n-2) + mo) % mo);//注意有可能结果为负，所以要处理
	}
}