#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int a[100005];
struct Dp
{
	int l;
	int r;
	int val;
}dp[100005];
const int inf = -200000000;
int main()
{
	int t;
	scanf("%d",&t);
	int num = 1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		int tmax = 1;
		dp[1].val = a[1];
		dp[1].l = 1;
		dp[1].r = 1;
		for(i=2;i<=n;i++)
		{
			if(dp[i-1].val>=0)
			{
				dp[i].val = dp[i-1].val + a[i];
				dp[i].l = dp[i-1].l;
				dp[i].r = i;
				if(dp[i].val>dp[tmax].val)
				{
					tmax = i;
				}
			}
			else
			{
				dp[i].val = a[i];
				dp[i].l = i;
				dp[i].r = i;
				if(dp[i].val>dp[tmax].val)
				{
					tmax = i;
				}
			}
		}
		printf("Case %d:\n",num);
		num++;
		printf("%d %d %d\n",dp[tmax].val,dp[tmax].l,dp[tmax].r);
		if(t>=1) printf("\n");
	}
}