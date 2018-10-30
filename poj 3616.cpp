#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<string.h>
typedef _int64 ll;
struct milk
{
	int s,e,v;
}a[1005];
ll max(ll x,ll y)
{
	if(x>y) return x;
	else return y;
}
bool cmp(milk x,milk y)
{
	if(x.s==y.s) return x.e<y.e;
	return x.s<y.s;
}
ll dp[1005];
int main()
{
	int n,m,r;
	scanf("%d %d %d",&n,&m,&r);
	int i,j;
	memset(dp,0,sizeof(dp));
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].v);
		a[i].e;
	}
	sort(a,a+m,cmp);
	dp[0] = a[0].v;
	for(i=0;i<m;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j].e+r<=a[i].s) dp[i] = max(dp[i],dp[j]+a[i].v);
			else dp[i] = max(dp[i],a[i].v);
		}
	}
	ll res = 0;
	for(i=0;i<m;i++) res = max(res,dp[i]);
	printf("%I64d\n",res);
	return 0 ;

}