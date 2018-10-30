#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#pragma comment(linker, "/STACK:10240000,10240000")
#define maxn 400010
int n,m,q,s;
int a[maxn];
vector<int> g[maxn];
vector<int> rg[maxn];
vector<int> vs;
vector<int> ng[maxn];
//vector<int> fa[maxn];
bool used[maxn];
int cmp[maxn];
bool visited[maxn];
//int num[maxn];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
struct road
{
	int from,to;
};
bool operator < (const road &x,const road &y)
{
	if(x.from==y.from) return x.to<y.to;
	return x.from<y.from;
}
set<road> t;
set<road>::iterator ite;
set<road> tt;
struct City
{
	int fmax,smax;
}city[maxn],dp[maxn];
void add_edge(int from,int to)
{
	g[from].push_back(to);
	rg[to].push_back(from);
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
void judge_arrive(int v)
{
	int i;
	used[v] = true;
	for(i=0;i<ng[v].size();i++) if(!used[ng[v][i]]) judge_arrive(ng[v][i]);
}
void adfs(int v,int par)//ÔÚngÉÏÃæ
{
	int i;
	road tm;
	if(par!=-1)
	{
		//int u = ng[v][i];
		//bool flag = false;
		if(city[v].fmax>city[par].fmax)
		{
			if(city[par].fmax>city[v].smax)
			{
				//flag = true;
				city[v].smax = city[par].fmax;
			}
		}
		else if(city[v].fmax<city[par].fmax)
		{
			//flag = true;
			city[v].smax = max(city[par].smax,city[v].fmax);
			city[v].fmax = city[par].fmax;
		}
		else
		{
			if(city[v].smax<city[par].smax) 
			{
				//flag = true;
				city[v].smax = city[par].smax;
			}
		}
		/*ite = tt.find(tm);
		if(ite!=tt.end() && !flag) return ;
		tm.from = par;
		tm.to = v;
		tt.insert(tm);*/
	}
	for(i=0;i<ng[v].size();i++)
	{
		adfs(ng[v][i],v);
	}
}
int scc()
{
	memset(used,0,sizeof(used));
	vs.clear();
	int v;
	for(v=0;v<n;v++)
	{
		if(!used[v]) dfs(v);
	}
	memset(used,0,sizeof(used));
	int k = 0;
	int i;
	for(i=vs.size()-1;i>=0;i--)
	{
		if(!used[vs[i]]) rdfs(vs[i],k++);
	}
	return k;
}
/*bool idfs(int v)
{
	int i;
	if(dp[v].fmax || dp[v].smax) return true;
	dp[v] = city[v];
	//if(num[v]>1) used[v] = true;
	bool flag = false;
	for(i=0;i<ng[v].size();i++)
	{
		int u = ng[v][i];
		if(idfs(u))
		{
			flag = true;
			if(dp[v].fmax<dp[u].fmax)
			{
				dp[v].smax = max(dp[v].fmax,dp[u].smax);
				dp[v].fmax = dp[u].fmax;
			}
			else if(dp[v].fmax>dp[u].fmax)
			{
				dp[v].smax = max(dp[v].smax,dp[u].fmax);
			}
			else
			{
				dp[v].smax = max(dp[v].smax,dp[u].smax);
			}
		}
	}
	if(flag || num[v]>1) used[v] = true;
	return used[v];
}*/
int main()
{
	scanf("%d %d %d %d",&n,&m,&q,&s);
	s--;
	int i,v;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		add_edge(v1-1,v2-1);
	}
	int sccnum = scc();
	for(i=0;i<sccnum;i++)
	{
		city[i].fmax = city[i].smax = 0;
	}
	city[cmp[s]].fmax = a[s];
	for(v=0;v<n;v++)
	{
		if(a[v]!=city[cmp[v]].fmax) city[cmp[v]].smax = max(city[cmp[v]].smax,a[v]);
		if(city[cmp[v]].fmax<city[cmp[v]].smax) swap(city[cmp[v]].fmax,city[cmp[v]].smax);
		for(i=0;i<g[v].size();i++)
		{
			int u = g[v][i];
			road tm;
			tm.from = cmp[v];
			tm.to = cmp[u];
			ite = t.find(tm);
			if(ite == t.end() && cmp[v]!=cmp[u])
			{
				t.insert(tm);
				ng[cmp[v]].push_back(cmp[u]);
				//fa[cmp[u]].push_back(cmp[v]);
			}
		}
	}
	memset(used,0,sizeof(used));
	//for(i=0;i<n;i++) printf("%d ",cmp[i]);
	/*for(v=0;v<3;v++)
	{
		for(i=0;i<ng[v].size();i++) printf("%d ",ng[v][i]);
		printf("\n");
	}*/
	//printf("num = %d\n",sccnum);
	judge_arrive(cmp[s]);
	for(i=0;i<n;i++)
	{
		if(used[cmp[i]]) visited[i] = true;
		//num[cmp[i]]++;
	}
	memset(used,0,sizeof(used));
	//idfs(cmp[s]);
	adfs(cmp[s],-1);
	for(i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		x--;
		if(!visited[x]) printf("-1 ");
		else
		{
			/*if(city[x].fmax>dp[x].fmax)
			{
				city[x].smax = max(city[x].smax,dp[x].fmax);
			}
			else if(city[x].fmax<dp[x].fmax)
			{
				city[x].smax = max(city[x].fmax,dp[x].smax);
				city[x].fmax = dp[x].fmax;
			}
			else
			{
				city[x].smax = max(city[x].smax,dp[x].smax);
			}*/
			if(city[cmp[x]].smax) printf("%d ",city[cmp[x]].smax);
			else printf("0 ");
		}
	}
	printf("\n");

}

/*
11 16 10 1
4 7 4 5 6 10 9 5 7 9 6
1 11
11 1
2 1
2 3
1 3
1 4
3 5
3 6
4 6
5 9
9 10
10 5
6 7
7 8
6 8
8 6
2 3 4 5 6 7 8 9 10 11


12 16 11 1
4 4 7 5 6 11 7 11 2 8 11 9
7 12
12 11 
1 11
11 7
5 4
1 2
1 3
1 4
1 5
3 6
4 6
6 7
6 8
5 8
8 9
8 10
2 3 4 5 6 7 8 9 10 11 12
*/