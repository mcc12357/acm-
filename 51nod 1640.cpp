#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#define maxn 200010
typedef _int64 ll;
const ll inf = -1000000000000;
struct edge
{
	int u,v;
	ll cost;
};
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
edge es[maxn];
int n,m;
int par[maxn],rank[maxn];
void init(int x)
{
	int i;
	for(i=0;i<=x;i++)
	{
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x)
{
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}
void unite(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x==y) return ;
	if(rank[x]<rank[y]) par[x] = y;
	else
	{
		par[y] = x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
bool cmp1(const edge& e1,const edge& e2)
{
	return e1.cost < e2.cost;
}
bool cmp2(const edge& e1,const edge& e2)
{
	return e1.cost > e2.cost;
}
int main()
{
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %I64d",&es[i].u,&es[i].v,&es[i].cost);
	}
	sort(es,es+m,cmp1);
	init(n);
	ll emax = inf;
	for(i=0;i<m;i++)
	{
		edge e = es[i];
		if(!same(e.u,e.v))
		{
			unite(e.u,e.v);
			emax = max(emax,e.cost);
		}
	}
	init(n);
	sort(es,es+m,cmp2);
	ll res = 0;
	for(i=0;i<m;i++)
	{
		edge e = es[i];
		if(!same(e.u,e.v) && e.cost<=emax)
		{
			unite(e.u,e.v);
			res += e.cost;
		}
	}
	printf("%I64d\n",res);
}