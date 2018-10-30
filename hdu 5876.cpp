#include<iostream>
using namespace std;
#include<stdio.h>
#include<set>
#include<string.h>
#include<queue>
typedef 250000 inf
set<int> g[200001];
int dis[200001];
int m,n;
int s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		int i;
		fill(dis+1,dis+m+1,inf);
		for(i=1;i<=m;i++) while(!g[i].) g[i].clear();
		for(i=1;i<=n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		scanf("%d",&s);
		queue<int> que;


	}
}
