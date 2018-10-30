#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
int const INF = 1 << 30;
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		int i,a[100001];
		for(i=0;i<t;i++)
			scanf("%d",&a[i]);
		int dp[100001];
		fill(dp,dp+t,INF);
		for(i=0;i<t;i++)
		{
			*lower_bound(dp,dp+t,a[i]) = a[i];
		}
		printf("%d\n",lower_bound(dp,dp+t,INF) - dp);
	}
}