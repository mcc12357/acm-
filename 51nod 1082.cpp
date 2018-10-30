#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
#define maxn 1000010
#define inf 1000000
ll res[maxn];
bool is[maxn];
bool f(int x)
{
	while(x)
	{
		if(x%10==7) return true;
		x /= 10;
	}
	return false;
}
int main()
{
	memset(is,0,sizeof(is));
	is[7] = 1;
	ll i;
	for(i=2;i*7<=inf;i++) is[i*7] = true;
	for(i=1;i<=inf;i++)
	{
		if(!is[i])
		{
			if(f(i)) is[i] = true;
		}
		if(!is[i])
		{
			res[i] = res[i-1] + i * i;
		}
		else
		{
			res[i] = res[i-1];
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%I64d\n",res[n]);
	}
}