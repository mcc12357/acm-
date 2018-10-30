#include<iostream>
using namespace std;
#include<stdio.h>
int dp[1005][35];//dp[i][j]表示第i秒走了j步
int a[1005];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int t,m;
	scanf("%d %d",&t,&m);
	int i,j;
	for(i=1;i<=t;i++) scanf("%d",&a[i]);
	dp[0][0] = 0;
	int sum = 0;
	for(i=1;i<=t;i++) if(a[i]==1) {sum++;dp[i][0] = sum;}
	else dp[i][0] = sum;
	sum = 0;
	for(i=1;i<=t;i++) 
	{
		if(i%2==1)
		{
			if(a[i]==2) {sum++;dp[i][i] = sum;}
			else dp[i][i] = sum;
		}
		else
		{
			if(a[i]==1) {sum++;dp[i][i] = sum;}
			else dp[i][i] = sum;
		}
	}
	for(i=1;i<=t;i++)
	{
		for(j=1;j<=m && j<=i-1;j++)
		{
				if(j%2==1)
				{
					if(a[i]==2) dp[i][j] = max(dp[i-1][j]+1,dp[i-1][j-1]+1);
					else
					{
						dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);
					}
				}
				else
				{
					if(a[i]==1) dp[i][j] = max(dp[i-1][j]+1,dp[i-1][j-1]+1);
					else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);
				}
		}
	}
	int res = 0;
	for(i=0;i<=m;i++) res = max(res,dp[t][i]);
	printf("%d\n",res);
	return 0;
}