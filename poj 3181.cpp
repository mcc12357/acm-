#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
int n,k;
ll dp[1005][1005];
ll f[1005];
int main()
{
	scanf("%d %d",&n,&k);
	int i,j;
	for(i=0;i<=n;i++) dp[i][i] = 1;
	ll tm = 0;
	f[0] = 1;
	for(j=1;j<=n;j++)
	{
		if(j>k) 
		{
			tm += f[j-k-1];
			f[j] -= tm;
		}
		for(i=1;i<=j;i++)
		{
			dp[i][j] = dp[i][j-i] + dp[i-1][j-1];
			f[j] += dp[i][j];
		}
	}
	printf("%I64d\n",f[n]);
}