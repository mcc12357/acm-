#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef long long ll;
ll a[55000];
ll min(ll x,ll y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	ll res = a[0];
	for(i=1;i<n;i++) 
	{
		a[i] += a[i-1];
		res = min(res,a[i]);
	}
	printf("%lld\n",(ll)(-1)*res);
}