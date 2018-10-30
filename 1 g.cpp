#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 100010
/*struct Pie
{
	int x,t;
}pie[maxn];
bool cmp(Pie a,Pie b)
{
	return a.t<b.t;
}*/
int dp[maxn][11];
int a[maxn][11];
int n;
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	while(~scanf("%d",&n) && n)
	{
		int i,j,x,t;
		/*for(i=0;i<n;i++) scanf("%d %d",&pie[i].x,&pie[i].t);
		sort(pie,pie+n,cmp);*/
		memset(a,0,sizeof(a));
		int m = 0;
		for(i=0;i<n;i++) 
		{
			scanf("%d %d",&x,&t);
			a[t][x]++;
			m = max(m,t);
		}
		memset(dp,-1,sizeof(dp));
		dp[0][5] = 0;
		for(i=1;i<=m;i++)
		{
			for(j=0;j<=10;j++)
			{
				if(j==0 && (dp[i-1][0]>=0 || dp[i-1][1]>=0)) dp[i][j] = max(dp[i-1][0],dp[i-1][1]) + a[i][j];
				else if(j==10 && (dp[i-1][9]>=0 || dp[i-1][10]>=0)) dp[i][j] = max(dp[i-1][9],dp[i-1][10]) + a[i][j];
				else if(j!=0 && j!=10 && (dp[i-1][j-1]>=0 || dp[i-1][j]>=0 || dp[i-1][j+1]>=0)) dp[i][j] = max(max(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]) + a[i][j];
			}
		}
		int ans = 0;
		for(i=0;i<=10;i++) ans = max(ans,dp[m][i]);
		printf("%d\n",ans);

	}
}