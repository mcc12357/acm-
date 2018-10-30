#include<iostream>
using namespace std;
#include<stdio.h>
int dp[12885];
int w[3405],val[3405];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=0;i<m;i++) scanf("%d %d",&w[i],&val[i]);
	for(i=0;i<m;i++)
		for(j=n;j>=w[i];j--) dp[j] = max(dp[j],dp[j-w[i]]+val[i]);
	printf("%d\n",dp[n]);

}