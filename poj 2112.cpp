#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#define maxn 800
int match[maxn];
vector<int> g[maxn];
bool used[maxn];
int m,n,k;
int d[maxn][maxn];
const int inf = 100000;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
bool dfs(int v)
{
	used[v] = true;
	int i;
	for(i=0;i<g[v].size();i++)
	{
		int u = g[v][i],w = match[u];
		if(w<0 || !used[w]&&dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
int bimat(int V)
{
	int res = 0;
	memset(match,-1,sizeof(match));
	int v;
	for(v=1;v<=V;v++)
	{
		if(match[v]<0)
		{
			memset(used,0,sizeof(used));
			if(dfs(v)) res++;
		}
	}
	return res;
}
bool f(int x)
{
	int i,j,p;
	for(i=m+1;i<=m+n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(d[i][j]<=x && d[i][j])
			{
				for(p=1;p<=k;p++)
				{
					int mn = (j-1) * k + p;
					int cn = (k-1) * m + i;
					g[mn].push_back(cn);
					g[cn].push_back(mn);
				}
			}
		}
	}
	int res = bimat(k*m+n);
	if(res>=n) return true;
	return false;
}
int main()
{
	while(~scanf("%d %d %d",&m,&n,&k))
	{
		int i,j,p;
		for(i=1;i<=m+n;i++)
		{
			for(j=1;j<=m+n;j++)
			{
				scanf("%d",&d[i][j]);
				if(i!=j && !d[i][j]) d[i][j] = inf;
			}
		}
		for(p=1;p<=m+n;p++)
			for(i=1;i<=m+n;i++)
				for(j=1;j<=m+n;j++)
				{
					d[i][j] = min(d[i][j],d[i][p]+d[p][j]);
				}
		int l = 1,r = 100000;
		while(r-l>1)
		{
			for(i=0;i<800;i++) g[i].clear();
			int mid = (l + r) / 2;
			if(f(mid))
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		for(i=0;i<800;i++) g[i].clear();
		if(f(l)) printf("%d\n",l);
		else printf("%d\n",r);
	}
}