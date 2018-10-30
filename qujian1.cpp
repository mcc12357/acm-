#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 110
int n;
int dp[maxn][maxn];
int a[maxn];
int sum[maxn];
const int inf = 2000000;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i,j,k;
		sum[0] = 0;
		for(i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			sum[i] = (sum[i-1] + a[i]) % 100;
		}
		//memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++) dp[i][j] = inf;
		for(i=1;i<=n;i++) dp[i][i] = 0;
		for(i=1;i<n;i++)//i为长度
		{
			for(j=1;j+i<=n;j++)//j为起点
			{
				int r = j + i;
				for(k=j;k<r;k++)
				{
					dp[j][r] = min(dp[j][r],dp[j][k]+dp[k+1][r]+((sum[k]-sum[j-1]+100)%100) * ((sum[r]-sum[k]+100)%100));
				}
			}
		}
		printf("%d\n",dp[1][n]);
		
	}
}
