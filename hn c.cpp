#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
#define maxn 100010
vector<int> g[maxn];
int dp[maxn][10];//表示其子孙节点与i相距为j的个数
int ans[maxn][10];//表示所有节点中与i相距为j的个数，ans[i][j] = dp[i][j] + ans[par][j-1] - dp[par][j-2];
int res[maxn];
void dfs(int cur,int par,int k)
{
	int i;
	dp[cur][k] = 0;
	for(i=0;i<g[cur].size();i++)
	{
		int u = g[cur][i];
		if(u==par) continue;
		dfs(u,cur,k);
		dp[cur][k] += dp[u][k-1];
	}
}
void sdfs(int cur,int par,int k)
{
	int i;
	ans[cur][k] = 0;
	for(i=0;i<g[cur].size();i++)
	{
		int u = g[cur][i];
		if(u==par) continue;
		sdfs(u,cur,k);
	}
	if(k==1) 
	{
		if(cur!=1) ans[cur][k] = dp[cur][k] + 1;
		else ans[cur][k] = dp[cur][k];
	}
	else
	{
		if(cur!=1) ans[cur][k] = dp[cur][k] + ans[par][k-1] - dp[cur][k-2];
		else ans[cur][k] = dp[cur][k];
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int num = 1;
	while(t--)
	{
		int n,i,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=n-1;i++) 
		{
			int a,b;
			scanf("%d %d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		//g[0].push_back(1);
		//g[1].push_back(0);
		memset(dp,0,sizeof(dp));
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n;i++) 
		{
			ans[i][0] = 1;
			dp[i][0] = 1;
		}
		for(i=1;i<=6;i++)
		{
			dfs(1,1,i);
		}
		//for(i=1;i<=n;i++) dp[i][0] = 0;
		for(i=1;i<=6;i++)
		{
			sdfs(1,1,i);
		}
		/*for(i=1;i<=n;i++) 
		{
			for(j=1;j<=6;j++) printf("%d ",ans[i][j]);
			printf("\n");
		}*/
		memset(res,0,sizeof(res));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=6;j++) res[i] += ans[i][j];
		}
		printf("Case #%d:\n",num);
		num++;
		for(i=1;i<=n;i++) printf("%d\n",res[i]);
	}
}
/*
1 
8 
1 2 
2 3 
3 4 
4 5 
5 6 
6 7 
7 8

5
12
1 2
1 3
2 4
2 5
3 6
5 9
6 7
6 8
8 10
8 11
8 12

4
4
1 2
1 3
2 4
*/