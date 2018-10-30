#include<iostream>
using namespace std;
#include<stdio.h>
typedef _int64 ll;
int p,a;
/*ll mod_pow(ll x,ll n)
{
	ll res = 1;
	while(n>0)
	{
		if(n&1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}*/
int main()
{
	scanf("%d %d",&p,&a);
	ll i;
	bool flag = false;
	for(i=1;i<=p;i++)
	{
		if(i*i%p==a)
		{
			flag = true;
			printf("%I64d ",i);
		}
	}
	if(!flag) printf("No Solution\n");
	else printf("\n");
}