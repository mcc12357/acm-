#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 100010
typedef _int64 ll;
ll a[maxn],dp[maxn];
ll suml[maxn],sumr[maxn],maxl[maxn],maxr[maxn];
int n;
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) 
	{
		scanf("%I64d",&a[i]);
	}
	suml[0] = a[0];
	maxl[0] = max(0,a[0]);
	sumr[n] = 0;
	maxr[n] = 0;
	for(i=1;i<n;i++)
	{
		suml[i] = suml[i-1] + a[i];
		maxl[i] = max(maxl[i-1],suml[i]);
	}
	for(i=n-1;i>=0;i--)
	{
		sumr[i] = sumr[i+1] + a[i];
		maxr[i] = max(maxr[i+1],sumr[i]);
	}
	ll res = 0;
	dp[0] = a[0];
	for(i=1;i<n;i++)
	{
		if(dp[i-1]>0)
		{
			dp[i] = dp[i-1] + a[i];
		}
		else
		{
			dp[i] = a[i];
		}
		res = max(res,dp[i]);
	}
	for(i=0;i<n-1;i++)
	{
		res = max(res,maxl[i]+maxr[i+1]);
	}
	//for(i=0;i<2*n-1;i++) res = max(res,dp[i]);
	printf("%I64d\n",res);
}