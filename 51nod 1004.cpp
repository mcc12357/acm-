#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
int n;
const int mod = 10;
ll pow(ll x,int k,int mod)
{
	int	res = 1;
	while(k)
	{
		if(k&1) res = (res * x) % mod;
		x = (x * x) % mod;
		k >>= 1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	ll res = pow(n,n,mod);
	printf("%I64d\n",res);
}