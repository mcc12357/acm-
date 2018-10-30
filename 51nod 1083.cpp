#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef long long ll;
#define maxn 510
int a[maxn][maxn];
ll dp[maxn][maxn];
int n;
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) scanf("%d",&a[i][j]);
	dp[0][0] = a[0][0];
	for(i=1;i<n;i++) 
	{
		dp[0][i] = dp[0][i-1] + a[0][i];
		dp[i][0] = dp[i-1][0] + a[i][0];
	}
	for(i=1;i<n;i++)
		for(j=1;j<n;j++)
		{
			dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + a[i][j];
		}
	ll res = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) res = max(res,dp[i][j]);
	printf("%lld\n",res);
}