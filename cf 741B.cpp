#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int a[200000],num[200000];
typedef _int64 ll;
int main()
{
	int n,x;
	scanf("%d %d",&n,&x);
	int i;
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	ll ans = 0;
	for(i=0;i<n;i++)
	{
		int tm = a[i] ^ x;
		if(tm!=a[i])
		{
			ans += num[tm];
		}
		else ans += (num[tm] - 1);
	}
	printf("%I64d\n",ans/2);
}
