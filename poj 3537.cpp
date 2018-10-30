#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")//²»¼Ó»á±¬Õ»
int dp[10000];
int dfs(int n)
{
	if(n<=0) return 0;
	if(dp[n]!=-1) return dp[n];
	int i;
	bool vis[10000];
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++) vis[dfs(i-3)^dfs(n-i-2)] = 1;
	for(i=0;;i++) if(!vis[i]) return dp[n] = i;
}
int main()
{
	int n;
	memset(dp,-1,sizeof(dp));
	while(~scanf("%d",&n))
	{
		if(dp[n]!=-1)
		{
			if(dp[n]) printf("1\n");
			else printf("2\n");
		}
		else
		{
			if(dfs(n)) printf("1\n");
			else printf("2\n");
		}
	}
}