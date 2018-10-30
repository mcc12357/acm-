#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n;
int a[105],b[105];
int dp[200100];
const int inf = -300000;
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%d",&n);
	int i,j;
	int zero = n * 1000 + 1;
	//int zero = 13;
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
	for(j=0;j<=2*zero+20;j++)
	{
		if(j==zero) dp[j] = 0;
		else dp[j] = inf;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]<0) 
		{
			for(j=0;j<=2*zero+5;j++)
			{
				if(j-a[i]<=2*zero+5 && dp[j-a[i]]!=inf) dp[j] = max(dp[j],dp[j-a[i]]+a[i]+b[i]);
			}
		}
		else
		{
			for(j=2*zero+5;j>=a[i];j--)
			{
				if(j-a[i]>=0 && dp[j-a[i]]!=inf) dp[j] = max(dp[j],dp[j-a[i]]+a[i]+b[i]);
			}
		}
	}
	int ans = 0;
	for(i=zero;i<=200005;i++)
	{
		if(dp[i]>=i-zero) ans = max(ans,dp[i]);
	}
	printf("%d\n",ans);
}
/*
2
-1 2
3 -2
*/
