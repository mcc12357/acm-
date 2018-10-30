#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
typedef long long ll;
struct Cow
{
	ll x;
	ll t;
}cow[100005];
int n;
bool cmp(Cow a,Cow b)
{
	if(a.x==b.x) return a.t>b.t;
	return a.x<b.x;
}
ll sum[100005];
ll ans1,ans2;
ll min(ll x,ll y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d %d",&cow[i].t,&cow[i].x);
	sort(cow+1,cow+n+1,cmp);
	memset(sum,0,sizeof(sum));
	for(i=1;i<=n;i++) sum[i] = sum[i-1] + cow[i].x;
	ans1 = 0;
	ans2 = 0;
	for(i=n;i>1;i--)
	{
		ans1 += cow[i].t * sum[i-1];
	}
	int k = 1;
	for(i=2;i<=n;i++)
	{
		if(cow[i].t>cow[k].t)
		{
			k = i;
		}
		if(cow[i].t==cow[k].t && cow[i].x<cow[k].x)
		{
			k = i;
		}
	}
	for(i=k;i>1;i--) 
	{
		swap(cow[i].t,cow[i-1].t);
		swap(cow[i].x,cow[i-1].x);
	}
	memset(sum,0,sizeof(sum));
	for(i=1;i<=n;i++) sum[i] = sum[i-1] + cow[i].x;
	for(i=n;i>1;i--)
	{
		ans2 += cow[i].t * sum[i-1];
	}
	ans1 = min(ans1,ans2);
	printf("%lld\n",2*ans1);
}