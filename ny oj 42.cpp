#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
int m,n;
vector<int> g[1005];
int visited[1005][1005];
int x;
int flag;
void dfs(int s)
{
	if(x==n) {flag = 1;return ;}
	int i;
	for(i=0;i<g[s].size();i++)
	{
		if(visited[s][g[s][i]]) continue;
		if(!visited[s][g[s][i]])
		{
			x++;
			visited[s][g[s][i]] = 1;
			visited[g[s][i]][s] = 1;
			dfs(g[s][i]);
		}
		x--;
		visited[s][g[s][i]] = 0;
		visited[g[s][i]][s] = 0;
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,t1,t2;
		x = 0;
		flag = 0;
		for(i=0;i<1005;i++) g[i].clear();
		scanf("%d %d",&m,&n);
		for(i=0;i<n;i++) 
		{
			scanf("%d %d",&t1,&t2);
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		//int flag = 0;
		for(i=1;i<=m;i++) dfs(i);
		if(flag) printf("Yes\n");
		else printf("No\n");
		
	}
	return 0;
}