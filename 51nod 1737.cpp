#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
#define maxn 100010
typedef long long ll;
struct edge
{
	int to,val;
};
int n;
vector<edge> g[maxn];
bool vis[maxn];
int son[maxn];//以i为根的子树的节点数，不包含自身i
int zx;//重心
int tmax = maxn;
ll d[maxn];
ll ans = 0;
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
void dfs(int u)
{
	vis[u] = 1;
	son[u] = 0;
	int tmp = 0;
	int i;
	for(i=0;i<g[u].size();i++)
	{
		int v = g[u][i].to;
		if(!vis[v])
		{
			dfs(v);
			son[u] += son[v] + 1;
			tmp = max(tmp,son[v]+1);
		}
	}
	tmp = max(tmp,n - son[u] - 1);
	if(tmp<tmax)
	{
		zx = u;
		tmax = tmp;
	}
}
void ndfs(int u,int par,ll dis)
{
	int i;
	ans += d[u];
	for(i=0;i<g[u].size();i++)
	{
		int v = g[u][i].to;
		if(v==par) continue;
		d[v] = dis+g[u][i].val;
		ndfs(v,u,dis+g[u][i].val);
	}
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edge e;
		e.to = b,e.val = c;
		g[a].push_back(e);
		e.to = a;
		g[b].push_back(e);
	}
	dfs(1);
	ndfs(zx,-1,0);
	//for(i=1;i<=n;i++) ans += d[i];
	printf("%lld\n",ans);
}