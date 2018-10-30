#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
typedef long long ll;
#define maxn (1<<20)+5
ll w[maxn],v[maxn];
struct Bag
{
	ll ww;
	ll vv;
}bag1[maxn];
int n;
ll W;
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
bool cmp(Bag x,Bag y)
{
	if(x.ww==y.ww) return x.vv<y.vv;
	return x.ww<y.ww;
}
int main()
{
	while(~scanf("%d %lld",&n,&W))
	{
		int i,j;
		ll res = 0;
		for(i=0;i<n;i++)
		{
			scanf("%lld %lld",&w[i],&v[i]);
		}
		int n1 = n / 2;
		for(i=0;i<(1<<n1);i++)
		{
			ll tw = 0,tv = 0;
			for(j=0;j<n1;j++)
			{
				if((i>>j)&1)
				{
					tw += w[j];
					tv += v[j];
				}
			}
			bag1[i].vv = tv;
			bag1[i].ww = tw;
		}
		sort(bag1,bag1+(1<<n1),cmp);
		int m = 1;
		for(i=1;i<(1<<n1);i++)
		{
			if(bag1[i].vv>bag1[m-1].vv)
			{
				bag1[m].vv = bag1[i].vv;
				bag1[m].ww = bag1[i].ww;
				m++;
			}
		}
		int n2 = n - n1;
		for(i=0;i<(1<<n2);i++)
		{
			ll tw = 0,tv = 0;
			for(j=n1;j<n;j++)
			{
				if((i>>(j-n1))&1)
				{
					tw += w[j];
					tv += v[j];
				}
			}
			if(W>=tw)
			{
				int l = 0,r = m - 1;
				while(r-l>1)
				{
					int mid = (l + r) / 2;
					if(bag1[mid].ww>W-tw) r = mid;
					else l = mid;
				}
				if(bag1[r].ww<=W-tw) res = max(res,bag1[r].vv+tv);
				else res = max(res,bag1[l].vv+tv);
			}
		}
		printf("%lld\n",res);
	}
}
