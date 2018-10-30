#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
int d1[5005];
int d2[5005];
//short cost[5005][5005];
//int used[5005];
const int inf = 30000000;
int m,n;
struct edge
{
	int from,to,cost;
};
struct ss
{
	int x;
	int dis;
};
bool operator < (const ss &a,const ss &b)
{
	return a.dis > b.dis;
}
vector<edge> g[5005];
priority_queue<ss> que;
void dijkstra(int s)
{
	fill(d1,d1+m+1,inf);
	fill(d2,d2+m+1,inf);
	//memset(used,0,sizeof(used));
	d1[s] = 0;
	ss tm;
	tm.x = 1;
	tm.dis = 0;
	que.push(tm);
	while(!que.empty())
	{
		tm = que.top();
		que.pop();
		int i;
		if(tm.dis>d2[tm.x]) continue;
		for(i=0;i<g[tm.x].size();i++)
		{
			edge y = g[tm.x][i];
			int tmp = tm.dis+y.cost;
			ss kk;
			if(d1[y.to]>tmp)
			{
				swap(tmp,d1[y.to]);
				kk.dis = d1[y.to];
				kk.x = y.to;
				que.push(kk);
			}
			if(d2[y.to]>tmp && d2[y.to]>d1[y.to])
			{
				swap(tmp,d2[y.to]);
				kk.dis = d2[y.to];
				kk.x = y.to;
				que.push(kk);
			}
		}
	}
}
int main()
{
	scanf("%d %d",&m,&n);
	int i,j;
	int a,b,k;
	/*for(i=1;i<=m;i++)
		for(j=1;j<=m;j++) cost[i][j] = inf;*/
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a,&b,&k);
		edge tm;
		tm.from = a;
		tm.to = b;
		tm.cost = k;
		g[a].push_back(tm);
		tm.from = b;
		tm.to = a;
		g[b].push_back(tm);
	}
	dijkstra(1);
	printf("%d\n",d2[m]);

}