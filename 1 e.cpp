#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 1010
int n;
int a[maxn],dp[maxn];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	while(~scanf("%d",&n) && n)
	{
		int i,j;
		a[0] = 0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		int ans = 0;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[i]>a[j]) dp[i] = max(dp[i],dp[j] + a[i]);
			}
			ans = max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
}