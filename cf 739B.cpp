#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
#include<vector>
#define maxn 210000
int n;
ll a[maxn],path[maxn],p[maxn],d[maxn],pre[maxn],ans[maxn],res[maxn];
vector<ll> g[maxn];
void solve(int root,int c,ll s)//root是当前节点编号，c是当前节点所在层数，s是当前节点到1号根节点的距离
{
	path[c] = root;
	pre[c] = s;
	int l = 1,r = c;
	while(r>l)
	{
		int mid = (l + r) / 2;
		if(s-pre[mid]<=a[root]) r = mid;
			else l = mid + 1;
	}
	res[p[root]]++;
	res[path[r-1]]--;
	int i;
	for(i=0;i<g[root].size();i++)
	{
		int u = g[root][i];
		solve(u,c+1,s+d[u]);
	}
}
void dfs(int root)
{
	int i;
	ans[root] = res[root];
	for(i=0;i<g[root].size();i++)
	{
		int u = g[root][i];
		dfs(u);
		ans[root] += ans[u];
	}
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
	p[1] = 0;
	for(i=0;i<=n;i++) g[i].clear();
	for(i=2;i<=n;i++) 
	{
		scanf("%I64d %I64d",&p[i],&d[i]);
		g[p[i]].push_back(i);
	}
	solve(1,1,0);
	dfs(1);
	for(i=1;i<=n;i++)
	{
		if(i!=n) printf("%I64d ",ans[i]);
		else printf("%I64d\n",ans[i]);
	}
}
