#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1010
int n,m,v[maxn],s[maxn],p[maxn];
//int mm[2000];
const int inf = -2000000000;
int dp[maxn][2000];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
//bool used[maxn][2000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,k;
		//memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&m);
		//for(i=0;i<(1<<m);i++) mm[i] = inf;
		//memset(mm,0,sizeof(mm));
		memset(p,0,sizeof(p));
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&v[i],&s[i]);
			for(j=0;j<s[i];j++)
			{
				int tm;
				scanf("%d",&tm);
				p[i] += (1<<(tm-1));
			}
		}
		for(i=0;i<=n;i++) for(j=0;j<(1<<m);j++) dp[i][j] = inf;
		dp[0][0] = 0;
		//memset(used,0,sizeof(used));
		for(i=1;i<=n;i++)
		{
			//memset(used,0,sizeof(used));
			for(j=0;j<(1<<m);j++)
			{
				//used[j] = 1;
				dp[i][j^p[i]] = max(dp[i][j^p[i]],dp[i-1][j]+v[i]);
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
			}
		}
		printf("%d\n",dp[n][(1<<m)-1]);
	}
}
/*
5
4 3
3 2
1 2
4 1
3
5 2
2 3
1 3
1 2 3
*/