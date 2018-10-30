#include<iostream>
using namespace std;
#include<stdio.h>
int cost[505][505];
int v,e;
int mincost[505];
int a[505];
bool used[505];
const int inf = 1e6;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&v,&e);
		int i,j;
		for(i=1;i<=v;i++)
			for(j=1;j<=v;j++)
			{
				if(i==j) cost[i][j] = 0;
				else cost[i][j] = inf;
			}
		for(i=1;i<=e;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			cost[a][b] = c;
			cost[b][a] = c;
		}
		for(i=1;i<=v;i++)
		{
			mincost[i] = inf;
			used[i] = false;
		}
		mincost[1] = 0;
		int res = 0;
		while(true)
		{
			int v1 = -1;
			int u;
			for(u=1;u<=v;u++)
			{
				if(!used[u] && (v1==-1 || mincost[u]<mincost[v1])) v1 = u;
			}
			if(v1==-1) break;
			used[v1] = true;
			res += mincost[v1];
			for(u=1;u<=v;u++) mincost[u] = min(mincost[u],cost[v1][u]);
		}
		for(i=1;i<=v;i++) scanf("%d",&a[i]);
		int tm = a[1];
		for(i=1;i<=v;i++) tm = min(tm,a[i]);
		res += tm;
		printf("%d\n",res);

	}
}