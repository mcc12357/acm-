#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
int visited[105];
int val[105];
vector<int> g[105];
int n,k;
int dp[105][205];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
void dfs(int pos,int step)
{
	if(step==k)
	{
		return;
	}
	//if(dp[pos][step]) return ;
	int i;
	for(i=0;i<g[pos].size();i++)
	{
		visited[g[pos][i]] = 1;
		dp[g[pos][i]][step+1] = val[g[pos][i]];
		dfs(g[pos][i],step+1);
		if(!visited[pos]) 
		{
			dp[pos][step] = max(dp[pos][step],dp[g[pos][i]][step+1]+val[pos]);
			//visited[pos] = 0;
		}
		else
		{
			dp[pos][step] = max(dp[pos][step],dp[g[pos][i]][step+1]);
		}
	}
	//visited[pos] = 0;
}
int main()
{
	while(~scanf("%d %d",&n,&k))
	{
		int i,j;
		int a,b;
		for(i=1;i<=n;i++) scanf("%d",&val[i]);
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		memset(visited,0,sizeof(visited));
		memset(dp,0,sizeof(dp));
		visited[1] = 1;
		dp[1][0] = val[1];
		dfs(1,0);
		//pos = 1;
		/*for(i=0;i<k;i++)
		{
			for(j=0;j<g[pos].size();j++)
			{
				if(!visited[g[pos][j]]) 
				{
					dp[g[pos][j]][i+1] = max(dp[g[pos][j]][i+1],dp[pos][i] + val[g[pos][j]]);
					visited[g[pos][j]] = 1;
				}
				else
				{
					dp[g[pos][j]][i+1] = max(dp[g[pos][j]][i+1],dp[pos][i]);
				}
			}
		}*/
		int res = -1; 
		for(i=1;i<=n;i++) if(dp[i][k]>res) res = dp[i][k];
		printf("%d\n",res);
	}
}