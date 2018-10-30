#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#pragma comment(linker,"/STACK:102400000,1024000")
int n,m,p,a,b;
vector<int> g[35];
int t[15];
double d[35][35];
double dp[(1<<8)+5][35];
const double inf = 5000;
double min(double x,double y)
{
	if(x-y<1e-6) return x;
	return y;
}
double dfs(int S,int par,int v)
{
	if(v==b)
	{
		return dp[S][v] = 0;
	}
	if(!fabs(dp[S][v]-inf)<1e-6) return dp[S][v];
	int i,j;
	for(j=0;j<g[v].size();j++)
	{
		int u = g[v][j];
		if(u==par) continue;
		for(i=0;i<n;i++)
		{
			if(S>>i&1)
			{
				dp[S][v] = min(dp[S][v],dfs(S&~(1<<i),v,u)+d[u][v]*1.0/t[i]);
			}
		}
	}
	return dp[S][v];
}
int main()
{
	while(~scanf("%d %d %d %d %d",&n,&m,&p,&a,&b) && (n||m||p||a||b))
	{
		int i,j;
		a--;
		b--;
		for(i=0;i<n;i++) scanf("%d",&t[i]);
		for(i=0;i<=m;i++) g[i].clear();
		int x,y;
		for(i=0;i<(1<<n);i++)
		{
			for(j=0;j<m;j++) dp[i][j] = inf;
		}
		for(i=1;i<=p;i++)
		{
			scanf("%d %d",&x,&y);
			x--;y--;
			scanf("%lf",&d[x][y]);
			d[y][x] = d[x][y];
			g[x].push_back(y);
			g[y].push_back(x);
		}
		double res = dfs((1<<n)-1,a,a);
		if(fabs(res-inf)<1e-6) printf("Impossible\n");
		else printf("%.3f\n",res);
	}
}