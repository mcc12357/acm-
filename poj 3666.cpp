#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<cmath>
#include<algorithm>
#define maxn 2010
typedef long long ll;
int n;
const ll inf = 3000000000;
int a[maxn],b[maxn];
ll dp[maxn][maxn];
bool cmp(int x,int y)
{
	return x>y;
}
ll min(ll x,ll y)
{
	if(x>y) return y;
	return x;
}
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(b,b+n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) dp[i][j] = inf;
	for(i=0;i<n;i++) dp[0][i] = fabs(a[0]-b[i]);
	//printf("inf = %I64d\n",inf);
	for(i=1;i<n;i++)
	{
		ll tm = inf;
		for(j=0;j<n;j++)
		{
			tm = min(tm,dp[i-1][j]);
			dp[i][j] = tm + fabs(a[i]-b[j]);
		}
	}
	ll ans = inf;
	for(i=0;i<n;i++) ans = min(ans,dp[n-1][i]);
	sort(b,b+n,cmp);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) dp[i][j] = inf;
	for(i=0;i<n;i++) dp[0][i] = fabs(a[0]-b[i]);
	for(i=1;i<n;i++)
	{
		ll tm = inf;
		for(j=0;j<n;j++)
		{
			tm = min(tm,dp[i-1][j]);
			dp[i][j] = tm + fabs(a[i]-b[j]);
		}
	}
	for(i=0;i<n;i++) ans = min(ans,dp[n-1][i]);
	printf("%lld\n",ans);
}