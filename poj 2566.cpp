#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef _int64 ll;
const ll inf = 1000000005;
struct bound
{
	int num;
	ll val;
}a[100005];
ll min(ll x,ll y)
{
	if(x<y) return x;
	return y;
}
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
int n,m;
ll abs(ll x)
{
	if(x>0) return x;
	else return -x;
}
bool cmp(bound x,bound y)
{
	//if(x.val==y.val) return x.num>y.num;
	return x.val < y.val;
} 
int main()
{
	while(~scanf("%d %d",&n,&m) && (m||n))
	{
		int i,t,j,k;
		a[0].num = 0;
		a[0].val = 0;
		for(i=1;i<=n;i++) 
		{
			scanf("%d",&t);
			a[i].num = i;
			a[i].val = a[i-1].val + t;
		}
		sort(a,a+n+1,cmp);
		for(i=1;i<=m;i++)
		{
			int k;
			scanf("%d",&k);
			int s = 0,t = 1,low,up;
			ll temp = inf,res;
			while(s<=n && t<=n)
			{
				ll tem = a[t].val - a[s].val;
				if(abs(tem-k)<temp) 
				{
					res = tem;
					temp = abs(tem-k);
					low = a[s].num;
					up = a[t].num;
				}
				if(tem<k) t++;
				else if(tem>k) s++;
				else if(tem==k) break;
				if(s==t) t = s + 1;
			}
			if(low>up) swap(low,up);

			printf("%I64d %d %d\n",res,low+1,up);
		}
	}
	return 0;
}
