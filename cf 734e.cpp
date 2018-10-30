#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
int n;
#define maxn 200010
int a[maxn],b[maxn],color[maxn];
vector<int> g[maxn];
int k = 0;//联通分量个数
int cmp[maxn];
int dp[maxn][2];
int ans = 0;
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
void dfs(int root,int x)
{
	int i;
	cmp[x] = k;
	for(i=0;i<g[x].size();i++)
	{
		int v = g[x][i];
		if(v==root) continue;
		if(color[x]==color[v]) dfs(x,v);
	}
}
int dfs1(int par,int x)
{
	dp[x][0] = 0,dp[x][1] = 0;
	int i;
	for(i=0;i<g[x].size();i++)
	{
		int v = g[x][i];
		if(v==par) continue;
		dp[x][1] = max(dp[x][1],dfs1(x,v)+1);
		if(dp[x][0]<dp[x][1]) swap(dp[x][0],dp[x][1]);
	}
	ans = max(ans,dp[x][0] + dp[x][1]);
	return dp[x][0];
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&color[i]);
	for(i=0;i<=n;i++) 
	{
		g[i].clear();
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	memset(cmp,-1,sizeof(cmp));
	for(i=1;i<=n;i++) 
	{
		if(cmp[i]<0) 
		{
			dfs(i,i);
			k++;
		}
	}
	for(i=0;i<=k;i++) 
	{
		g[i].clear();
	}
	for(i=1;i<=n;i++)
	{
		if(cmp[a[i]]!=cmp[b[i]])
		{
			g[cmp[a[i]]].push_back(cmp[b[i]]);
			g[cmp[b[i]]].push_back(cmp[a[i]]);
		}
	}
	//printf("%d\n",g[0][0]);
	//for(i=1;i<=11;i++) printf("%d\n",cmp[i]);
	dfs1(0,0);
	printf("%d\n",(ans+1)/2);

}