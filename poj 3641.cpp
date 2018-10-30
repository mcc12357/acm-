#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef long long ll;
ll p,a;
ll mod_pow(ll x,ll n,ll mod)
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
bool isprime(int x)
{
	int i;
	for(i=2;i*i<=x;i++) 
	{
		if(x%i==0) return false;
	}
	return true;
}
int main()
{
	while(~scanf("%I64d %I64d",&p,&a) &&(p||a))
	{
		if(mod_pow(a,p,p)==a && !isprime(p)) printf("yes\n");
		else printf("no\n");
	}
}