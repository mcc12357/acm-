#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
const int inf = 1e7;
int n;
int cost[105][105];
int d[105];
int dp[1000005];
int val[105];
bool used[105];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
void dijkstra(int s)
{
	fill(d,d+n+1,inf);
	fill(used,used+n+1,false);
	d[s] = 0;
	while(true)
	{
		int v = -1;
		int u;
		for(u=0;u<=n;u++)
		{
			if(!used[u] && (v==-1 || d[u]<d[v])) v = u;
		}
		if(v==-1) break;
		used[v] = true;
		for(u=0;u<=n;u++)
		{
			d[u] = min(d[u],d[v] + cost[v][u]);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,m;
		scanf("%d %d %d",&s,&n,&m);
		int i,j;
		for(i=0;i<=n;i++) 
			for(j=0;j<=n;j++)
			{
				if(i==j) cost[i][j] = 0;
				else cost[i][j] = inf;
			}
		for(i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			cost[a][b] = min(cost[a][b],c);
			cost[b][a] = min(cost[b][a],c);
		}
		for(i=1;i<=n;i++) scanf("%d",&val[i]);
		dijkstra(0);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			for(j=s;j>=d[i];j--)
			{
				dp[j] = max(dp[j],dp[j-d[i]] + val[i]);
			}
		printf("%d\n",dp[s]);
	}
}