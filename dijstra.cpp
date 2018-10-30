#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#define maxn 110
const int inf = 1e6;
struct edge
{
	int to,val;
};
struct vertex
{
	int x,val;
};
struct cmp
{
	bool operator () (vertex a,vertex b)
	{
		return a.val>b.val;
	}
};
int d[maxn];
int n,m,s;
vector<edge> g[maxn];
priority_queue<vertex,vector<vertex>,cmp> q;
bool vis[maxn];
void init()
{
	int i;
	for(i=1;i<=n;i++) 
	{
		g[i].clear();
		d[i] = inf;
	}
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
}
int main()
{
	scanf("%d %d %d",&n,&m,&s);
	init();
	int i;
	int ta,tb,tc;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&ta,&tb,&tc);
		edge e;
		e.to = tb;
		e.val = tc;
		g[ta].push_back(e);
	}
	vertex v;
	v.x = s;
	v.val = 0;
	d[s] = 0;
	q.push(v);
	while(!q.empty())
	{
		v = q.top();
		q.pop();
		if(vis[v.x]) continue;
		vis[v.x] = true;
		for(i=0;i<g[v.x].size();i++)
		{
			int t = g[v.x][i].to;
			if(d[t] <= d[v.x] + g[v.x][i].val) continue;
			d[t] = d[v.x] + g[v.x][i].val;
			vertex u;
			u.x = t;
			u.val = d[t];
			q.push(u);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d = %d\n",i,d[i]);
	}
}
