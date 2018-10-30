#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
typedef _int64 ll;
ll c,hr,hb,wr,wb;
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%I64d %I64d %I64d %I64d %I64d",&c,&hr,&hb,&wr,&wb);
	ll ans = 0;
	ll i;
	for(i=0;i<=10000000;i++)
	{
		if(i*wr<=c)
		{
			ans = max(ans,(c-i*wr)/wb*hb+i*hr);
		}
		if(i*wb<=c)
		{
			ans = max(ans,(c-i*wb)/wr*hr+i*hb);
		}
	}
	printf("%I64d\n",ans);
}