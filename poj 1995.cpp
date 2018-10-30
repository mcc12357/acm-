#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef long long ll;
ll pow(ll x,ll n,int mod)
{
	ll res = 1;
	while(n>0)
	{
		if(n&1) res = (res * x) % mod;
		x = (x * x) % mod;
		n = (n >> 1);
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int mod;
		scanf("%d",&mod);
		int m;
		scanf("%d",&m);
		ll a,b;
		ll sum = 0;
		int i;
		for(i=1;i<=m;i++) 
		{
			scanf("%lld %lld",&a,&b);
			sum = (sum + pow(a,b,mod) ) % mod;
		}
		printf("%lld\n",sum);
	}
}