#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1000010
typedef long long ll;
const ll inf = 1e15;
int m,n;
ll dp[2][maxn];
int a[maxn];
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	while(~scanf("%d %d",&m,&n))
	{
		int i,j;
		memset(dp,0,sizeof(0));
		for(i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			dp[1][i] = dp[0][i] = 0;
		}
		ll ans;
		for(i=1;i<=m;i++)
		{
			ans = -inf;
			for(j=i;j<=n;j++)
			{
				dp[1][j] = max(dp[1][j-1],dp[0][j-1])+a[j];
				dp[0][j-1] = ans;
				ans = max(ans,dp[1][j]);
			}
		}
		printf("%lld\n",ans);
	}
}