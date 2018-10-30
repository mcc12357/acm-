#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
int happy[6005];
int boss[6005];
int dp[6005][2];
int used[6005];
typedef _int64 ll;
const ll inf = -10000000000;
vector<int> g[6005];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
void dfs(int m)
{   
	if(g[m].size()==0)
	{
		dp[m][1] = happy[m];
		dp[m][0] = 0;
		return ;
	}
	int i;
	for(i=0;i<g[m].size();i++)
	{
		if(used[i]) continue;
		dfs(g[m][i]);
		dp[m][0] += max(dp[g[m][i]][0],dp[g[m][i]][1]);
		dp[m][1] += dp[g[m][i]][0];
	}
	dp[m][1] += happy[m];
	used[m] = 1;
}
int main()
{
	int n,t1,t2;
	while(~scanf("%d",&n))
	{
		memset(boss,0,sizeof(boss));
		memset(dp,0,sizeof(dp));
		memset(used,0,sizeof(used));
		//scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++) scanf("%d",&happy[i]);
		while(~scanf("%d %d",&t1,&t2) && (t1||t2))
		{
			g[t2].push_back(t1);
			boss[t1] = t2;
		}
		for(i=1;i<=n;i++)
		{
			if(boss[i]==0) {dfs(i);break;}
		}
		ll res = inf;
		res = max(dp[i][0],dp[i][1]);
		printf("%I64d\n",res);
	}
	return 0;

}