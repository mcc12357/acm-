#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#define maxn 410
int n,m;
vector<int> g[maxn];
int match[maxn];
bool used[maxn];
bool dfs(int v)
{
	used[v] = true;
	int i;
	for(i=0;i<g[v].size();i++)
	{
		int u = g[v][i],w = match[u];
		if(w<0 || !used[w]&&dfs(w))
		{
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	return false;
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		int i,j;
		for(i=0;i<=n;i++) g[i].clear();
		int t,tm;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			for(j=1;j<=t;j++)
			{
				scanf("%d",&tm);
				tm += 200;
				g[i].push_back(tm);
				g[tm].push_back(i);
			}
		}
		int res = 0;
		memset(match,-1,sizeof(match));
		for(i=1;i<=n;i++)
		{
			if(match[i]<0)
			{
				memset(used,0,sizeof(used));
				if(dfs(i)) res++;
			}
		}
		printf("%d\n",res);
		//printf("%d %d %d %d %d\n",match[1],match[2],match[3],match[4],match[5]);
	}
}