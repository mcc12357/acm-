#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
typedef _int64 ll;
ll dp[25][25];
ll a,b;
int c[22];
int k = 0;
ll dfs(int pos,int x,int rt,bool flag,bool flag1)
{
	if(pos==-1) return rt;
	if(flag && flag1 && dp[pos][rt]!=-1) return dp[pos][rt];
	int y = flag ? 9 : c[pos];
	int i;
	ll ans = 0;
	for(i=0;i<=y;i++)
	{
		if(!flag1 && x==0 && i==0) 
		{
			ans += dfs(pos-1,x,rt,flag|i<y,flag1|i);
			continue;
		}
		if(i==x) ans += dfs(pos-1,x,rt+1,flag|i<y,flag1|i);
		else ans += dfs(pos-1,x,rt,flag|i<y,flag1|i);
	}
	if(flag && flag1) dp[pos][rt] = ans;
	return ans;
}
ll solve(ll x,int y)
{
	k = 0;
	while(x)
	{
		c[k++] = x % 10;
		x /= 10;
	}
	memset(dp,-1,sizeof(dp));
	ll res = dfs(k-1,y,0,0,0);
	return res;
}
int main()
{
	int i;
	scanf("%I64d %I64d",&a,&b);
	for(i=0;i<10;i++) printf("%I64d\n",solve(b,i)-solve(a-1,i));

}