#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 105
int n;
int cost[maxn][maxn];
const int inf = 1e5 + 5;
int mincost[maxn];
bool used[maxn];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	while(~scanf("%d",&n))
	{
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) scanf("%d",&cost[i][j]);
		for(i=0;i<n;i++)
		{
			mincost[i] = inf;
			used[i] = false;
		}
		mincost[0] = 0;
		int res = 0;
		while(true)
		{
			int v = -1,u;
			for(u=0;u<n;u++)
			{
				if(!used[u] && (v==-1 || mincost[u]<mincost[v])) v = u;
			}
			if(v==-1) break;
			used[v] = true;
			res += mincost[v];
			for(u=0;u<n;u++)
			{
				mincost[u] = min(mincost[u],cost[v][u]);
			}
		}
		printf("%d\n",res);
	}
}