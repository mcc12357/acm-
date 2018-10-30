#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 510
const int inf = 200000;
int d[maxn];
int val[maxn];
int cost[maxn][maxn];
bool used[maxn];
int n,m,s,e;
int vv[maxn];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&e);
	int i,j;
	for(i=0;i<n;i++) scanf("%d",&vv[i]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) 
		{
			if(i==j) cost[i][j] = 0;
			else cost[i][j] = inf;
		}
	int a,b,t;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&t);
		cost[a][b] = t;
		cost[b][a] = t;
	}
	for(i=0;i<n;i++)
	{
		used[i] = false;
		d[i] = inf;
		val[i] = 0;
	}
	d[s] = 0;
	val[s] = vv[s];
	while(true)
	{
		int v = -1;
		int u;
		for(u=0;u<n;u++)
		{
			if(!used[u]&&(v==-1||d[u]<d[v])) v = u;
		}
		if(v==-1) break;
		used[v] = true;
		for(u=0;u<n;u++)
		{
			if(d[u]>d[v]+cost[v][u])
			{
				d[u] = d[v] + cost[v][u];
				val[u] = val[v] + vv[u];
			}
			if(d[u]==d[v]+cost[v][u] && u!=v)
			{
				val[u] = max(val[u],val[v]+vv[u]);
			}
		}
	}
	printf("%d %d\n",d[e],val[e]);

}