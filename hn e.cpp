#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
typedef long long ll;
#define maxn 1000010
int n,k;
ll dp[maxn];
const int inf = 1000010;
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
struct S
{
	int x;
	int l,r;
	int val;
}s[maxn];
void init(int num)
{
	int i;
	for(i=1;i<=num;i++)
	{
		s[i].x = s[i].l = s[i].r = inf;
	}
}
void dfs(int root,int cur,int sum,int num)
{
	sum += s[cur].val;
	num++;
	if(sum<=k) 
	{
		dp[root] = max(dp[root],num);
		int tl = cur * 2,tr = cur * 2 + 1;
		if(tl<=n) dfs(root,tl,sum,num);
		if(tr<=n) dfs(root,tr,sum,num);
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&k);
		init(n);
		int i;
		for(i=1;i<=n;i++) scanf("%d",&s[i].val);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			s[i].x = i;
			int tl = 2 * s[i].x;
			int tr = 2 * s[i].x + 1;
			if(tl<=n) s[i].l = tl;
			if(tr<=n) s[i].r = tr;
		}
		for(i=1;i<=n;i++)
		{
			dfs(i,i,0,0);
		}
		int res = 0;
		for(i=1;i<n;i++) res = max(res,dp[i]);
		if(res) printf("%lld\n",res);
		else printf("-1\n");
	}
}