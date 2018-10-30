#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
const int mod = 1000000007;
ll pow(ll x,ll n)
{
	ll res = 1;
	while(n>0)
	{
		if(n&1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
int main()
{
	int n,a,b;
	ll i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&a,&b);
	}
	ll ans = 1;
	for(i=2;i<=n;i++)
	{
		ans = (2 * ans + pow(2,i-2)) % mod;
	}
	printf("%I64d\n",ans);

}