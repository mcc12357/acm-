//³¬Ê±
#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
typedef _int64 ll;
ll gcd(ll x,ll y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	ll a,b;
	while(~scanf("%I64d %I64d",&a,&b))
	{
		ll i;
		for(i=(ll)sqrt(b/a);i>=1;i--)
		{
			if(b%i==0)
			{
				if(gcd(i,b/i/a)==1) break;
			}
		}
		printf("%I64d %I64d\n",a*i,b/i);
	}
	return 0;
}