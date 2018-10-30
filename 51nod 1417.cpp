#include<iostream>
using namespace std;
#include<stdio.h>
typedef _int64 ll;
ll gcd(ll x,ll y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b;
		scanf("%I64d %I64d",&a,&b);
		ll x = a + 3 * b;
		ll y = 4 * a + 4 * b;
		ll d = gcd(x,y);
		printf("%I64d/%I64d\n",x/d,y/d);
	}
}