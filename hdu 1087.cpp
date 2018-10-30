#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
int n;
int a[1010];
int dp[1010];
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
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			dp[i] = a[i];
		}
		//dp[0] = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[i]>a[j]) dp[i] = max(dp[i],dp[j]+a[i]);
			}
		}
		ll res = 0;
		for(i=0;i<n;i++) res = max(res,dp[i]);
		printf("%I64d\n",res);
	}
}