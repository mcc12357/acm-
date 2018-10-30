#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<cmath>
#include<vector>
typedef _int64 ll;
#define maxn 1010
int n,c[maxn];
ll r[maxn],x[maxn],y[maxn];//注意要用long long
vector<int> g[maxn];
vector<int> rg[maxn];
vector<int> vs;
bool used[maxn];
int cmp[maxn];
int tmin[maxn];//i号强连通分量中的最小值
int count1 = 1;
bool covered[maxn];
bool is[maxn][maxn];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
void add_edge(int from,int to)
{
	g[from].push_back(to);
	rg[to].push_back(from);
}
ll f(int i,int j)
{
	return ( (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]) );
}
void dfs(int v)
{
	used[v] = true;
	int i;
	for(i=0;i<g[v].size();i++)
	{
		if(!used[g[v][i]]) dfs(g[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v,int k)
{
	used[v] = true;
	cmp[v] = k;
	int i;
	for(i=0;i<rg[v].size();i++)
	{
		if(!used[rg[v][i]]) rdfs(rg[v][i],k);
	}
}

int scc()
{
	memset(used,0,sizeof(used));
	vs.clear();
	int v,i;
	for(v=0;v<n;v++)
	{
		if(!used[v]) dfs(v);
	}
	memset(used,0,sizeof(used));
	int k = 0;
	for(i=vs.size()-1;i>=0;i--)
	{
		if(!used[vs[i]]) rdfs(vs[i],k++);
	}
	return k;
}

void ndfs(int x)
{
	used[x] = 1;
	int i;
	for(i=0;i<g[x].size();i++)
	{
		covered[g[x][i]] = 1;
		if(used[g[x][i]]) continue;
		ndfs(g[x][i]);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		scanf("%d",&n);
		memset(cmp,0,sizeof(cmp));
		vs.clear();
		for(i=0;i<n;i++) tmin[i] = 20000;
		for(i=0;i<=n;i++)
		{
			g[i].clear();
			rg[i].clear();
		}
		for(i=0;i<n;i++) scanf("%I64d %I64d %I64d %d",&x[i],&y[i],&r[i],&c[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				ll d = f(i,j);
				if((ll)r[i]*r[i]>=d)
				{
					add_edge(i,j);
				}
				if((ll)r[j]*r[j]>=d)
				{
					add_edge(j,i);
				}
			}
		//printf("%d\n",g[0][0]);
		int k = scc();
		for(i=0;i<n;i++)
		{
			tmin[cmp[i]] = min(tmin[cmp[i]],c[i]);
		}
		for(i=0;i<=k;i++) g[i].clear();
		memset(covered,0,sizeof(covered));
		memset(is,0,sizeof(is));
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(cmp[i]==cmp[j]) continue;
				if(!is[cmp[i]][cmp[j]])
				{
					ll d = f(i,j);
					if(d<=(ll)r[i]*r[i])
					{
						g[cmp[i]].push_back(cmp[j]);
						is[cmp[i]][cmp[j]] = 1;
					}
				}
				if(!is[cmp[j]][cmp[i]])
				{
					ll d = f(i,j);
					if(d<=(ll)r[j]*r[j])
					{
						g[cmp[j]].push_back(cmp[i]);
						is[cmp[j]][cmp[i]] = 1;
					}
				}
			}
		}
		memset(used,0,sizeof(used));
		for(i=0;i<n;i++)
		{
			if(!used[cmp[i]]) ndfs(cmp[i]);
		}
		ll ans = 0;
		//printf("k = %d\n",k);
		for(i=0;i<k;i++) 
		{
			if(!covered[i]) ans += tmin[i];
		}
		printf("Case #%d: ",count1);
		printf("%I64d\n",ans);
		count1++;
	}
}
/*
5
5
0 0 1 1
1 1 1 3
3 1 2 5
-1 0 3 10
0 -7 4 2
*/
