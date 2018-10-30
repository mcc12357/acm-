#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
int n;
ll max(ll x,ll y)
{
	if(x<y) return y;
	return x;
}
int a[510][510];
ll dp[510][510];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dp[1][1] = a[1][1];
	ll res = 0;
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			if(j==1) dp[i][j] = dp[i-1][j] + a[i][j];
			else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
		}
	for(i=1;i<=n;i++) res = max(res,dp[n][i]);
	printf("%I64d\n",res);
}