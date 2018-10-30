#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#define maxn 105
int n,m;
int man[maxn],bread[maxn];
double pos[maxn];
int sumflow;
const int inf = 99999;
int s,t;
int V;
struct edge
{
	int to,cap;
	double cost;
	int rev;
};
//vector<edge> g[maxn];
vector<vector<edge> > g;
double dist[maxn];
int prevv[maxn],preve[maxn];
void add_edge(int from,int to,int cap,double cost)
{
	g[from].push_back((edge){to,cap,cost,g[to].size()});
	g[to].push_back((edge){from,0,-cost,g[from].size()-1});
}
double min_cost_flow(int s,int t,int f)
{
	double res = 1.0;
	V = t + 1;
	int v,i;
	while(f>0)
	{
		fill(dist,dist+V,inf);
		dist[s] = 0;
		bool update = true;
		while(update)
		{
			update = false;
			for(v=0;v<V;v++)
			{
				if(dist[v]==inf) continue;
				for(i=0;i<g[v].size();i++)
				{
					edge &e = g[v][i];
					if(e.cap>0 && (dist[e.to]-dist[v]+e.cost) > 1e-6)
					{
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}	
		}
		if(dist[t]==inf) return -1;
		int d = f;
		for(v=t;v!=s;v = prevv[v])
		{
			d = min(d,g[prevv[v]][preve[v]].cap);
		}
		for(v=t;v!=s;v=prevv[v])
		{
			res *= pow((1-g[prevv[v]][preve[v]].cost),d);
		}
		f -= d;
		for(v=t;v!=s;v=prevv[v])
		{
			edge &e = g[prevv[v]][preve[v]];
			e.cap -= d;
			g[v][e.rev].cap += d;
		}
	}
	return res;
}
/*void min(int x,int y)
{
	if(x<y) return x;
	return y;
}
*/
int main()
{
	int r;
	scanf("%d",&r);
	while(r--)
	{
		scanf("%d %d",&n,&m);
		int i;
		s = n;
		t = s + 1;
		sumflow = 0;
		for(i=0;i<=n;i++) g[i].clear();
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&man[i],&bread[i]);
			int tm = min(man[i],bread[i]);
			man[i] -= tm;
			bread[i] -= tm;
			sumflow += man[i];
		}
		int a,b;
		double p;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %lf",&a,&b,&p);
			add_edge(a-1,b-1,1,0);
			add_edge(a-1,b-1,inf,p);
		}
		for(i=0;i<n;i++)
		{
			add_edge(s,i,man[i],0);
		}
		for(i=0;i<n;i++)
		{
			add_edge(i,t,bread[i],0);
		}
		printf("%.2f\n",1-min_cost_flow(s,t,sumflow));
	}
}

/*
struct edge
{
	int to,cap,cost,rev;
};
vector<edge> g[maxn];
void add_edge(int from,int to,int cap,int cost)
{
	g[from].push_back((edge){to,cap,cost,g[to].size()});
	g[to].push_back((edge){from,0,-cost,g[from].size()-1});
}
*/