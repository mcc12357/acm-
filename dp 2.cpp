#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
double dp[100005];
int jump[100005];
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m) && (m||n))
	{
		int i,j;
		memset(dp,0,sizeof(dp));
		memset(jump,-1,sizeof(jump));
		int x,y;
		for(i=1;i<=m;i++) 
		{
			scanf("%d %d",&x,&y);
			jump[x] = y;
		}
		dp[n] = 0;
		for(i=n-1;i>=0;i--)
		{
			if(jump[i]!=-1) dp[i] = dp[jump[i]];
			else
			{
				for(j=1;j<=6;j++)
				{
					if((i+j)<=n)
					{
						dp[i] += 1.0 / 6 * dp[i+j];//×¢Òâ±ØÐëÓÃ1.0
					}
				}
				dp[i]++;
			}
		}
		printf("%.4f\n",dp[0]);
	}
}