#include<iostream>
using namespace std;
#include<stdio.h>
typedef _int64 ll;
const int mod = 1e9+7;
int n;
ll a[1010];
int main()
{
	a[1] = 1;
	a[2] = 2;
	ll i;
	for(i=3;i<=1000;i++) a[i] = (a[i-1] + a[i-2]) % mod;
	scanf("%d",&n);
	printf("%I64d\n",a[n]);
}