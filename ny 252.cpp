#include<iostream>
using namespace std;
#include<stdio.h>
int dp[45][2];
int main()
{
	int i;
	dp[1][0] = 2;
	dp[1][1] = 1;
	for(i=2;i<=40;i++)
	{
		dp[i][0] = 2 * dp[i-1][0] - dp[i-1][1];
		dp[i][1] = dp[i-1][0] - dp[i-1][1];
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m;
		scanf("%d",&m);
		printf("%d\n",dp[m][0]);
	}
	return 0;
}