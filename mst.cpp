#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#define maxn 105
int n,m;//n个节点m条边
const int inf = 1e6;
struct vertex
{
	int x,val;
};
struct edge
{
	int to,val;
};
struct cmp
{
	bool operator ()(vertex a,vertex b)
	{
		return a.val>b.val;
	}
};
/*bool operator < (vertex a,vertex b)
{
	return a.val<b.val;
}*/
vector<edge> g[maxn];
priority_queue<vertex,vector<vertex>,cmp> q;
int total = 0;
int path[maxn];
bool used[maxn];
int mst[maxn];
void init()
{
	int i;
	for(i=1;i<=n;i++) 
	{
		g[i].clear();
		mst[i] = inf;
	}
	memset(used,0,sizeof(used));
	memset(path,0,sizeof(path));
	while(!q.empty()) q.pop();
}
int main()
{
	scanf("%d %d",&n,&m);
	init();
	int i;
	int ta,tb,val;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&ta,&tb,&val);
		edge e;
		e.to = tb,e.val = val;
		g[ta].push_back(e);
		e.to = ta;
		g[tb].push_back(e);
	}
	vertex v;
	v.x = 1;
	v.val = 0;
	q.push(v);
	while(!q.empty())
	{
		v = q.top();
		q.pop();
		if(used[v.x]) continue;
		used[v.x] = true;
		total += v.val;
		for(i=0;i<g[v.x].size();i++)
		{
			int t = g[v.x][i].to;
			if(used[t]) continue;
			int k = g[v.x][i].val;
			if(g[v.x][i].val<mst[t])
			{
				mst[t] = g[v.x][i].val;
				path[t] = v.x;
				vertex u;
				u.x = t;
				u.val = mst[t];
				q.push(u);
			}
		}
	}
	printf("total = %d\n",total);
	for(i=1;i<=n;i++) 
	{
		if(path[i]!=0) printf("%d %d\n",i,path[i]);
	}

}
/*
6 8
1 2 2
1 3 6
2 3 5
2 5 7
2 6 3
5 6 10
3 6 3
1 4 4
*/