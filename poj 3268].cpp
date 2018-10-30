#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1005
//#define ll _int64
typedef _int64 ll;
ll cost1[maxn][maxn],cost2[maxn][maxn];
ll d1[maxn],d2[maxn];
int used[maxn];
const ll inf = 999999999;
int n,m,x;
ll min(ll a,ll b)
{
	if(a<b) return a;
	return b;
}
ll max(ll a,ll b)
{
	if(a>b) return a;
	return b;
}
void dijkstra(int s,ll cost[maxn][maxn],ll d[maxn])
{
	fill(d,d+n+1,inf);
	memset(used,0,sizeof(used));
	d[s] = 0;
	while(true)
	{
		int v = -1;
		int u;
		for(u=1;u<=n;u++)
		{
			if(!used[u] && (v==-1||d[u]<d[v])) v = u;
		}
		if(v==-1) break;
		used[v] = true;
		for(u=1;u<=n;u++)
		{
			d[u] = min(d[u],d[v]+cost[v][u]);
		}
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&x);
	int i,j,k;
	for(i=0;i<=maxn;i++)
		for(j=0;j<=maxn;j++)
		{
			if(i==j) 
			{
				cost1[i][j] = 0;
				cost2[i][j] = 0;
				continue;
			}
			cost1[i][j] = inf;
			cost2[i][j] = inf;
		}
	int a,b,c;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(cost1[a][b]>c) cost1[a][b] = c;
		if(cost2[b][a]>c) cost2[b][a] = c;
	}
	dijkstra(x,cost1,d1);
	dijkstra(x,cost2,d2);
	ll ans = 0;
	for(i=1;i<=n;i++)
	{
		ans = max(ans,d1[i]+d2[i]);
	}
	printf("%I64d\n",ans);
	
}