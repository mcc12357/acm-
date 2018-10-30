#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
typedef long long ll;
#define MAX 1100 
int num[MAX];
int prime[MAX];
bool isprime[MAX];
int init(int n)
{
	int p = 0;
	int i,j;
	for(i=0;i<=n;i++) isprime[i] = true;
	isprime[0] = isprime[1] = false;
	for(i=2;i<=n;i++)
	{
		if(isprime[i])
		{
			prime[p++] = i;
			for(j=2*i;j<=n;j+=i) isprime[j] = false;
		}
	}
	return p;
}
ll f(int x)
{
	int i;
	if(x==0) return 1;
	ll res = 1;
	for(i=2;i<=x;i++) res *= i;
	return res;
}
int main()
{
	int n;
	int t = init(MAX);
	//printf("%d\n",t);
	while(~scanf("%d",&n))
	{
		memset(num,0,sizeof(num));
		int i;
		int ans1 = 0;
		int m = n;
		for(i=0;i<t && prime[i]*prime[i]<=n;i++)
		{
			while(n%prime[i]==0)
			{
				num[prime[i]]++;
				n /= prime[i];
				ans1++;
			}
		}
		if(n!=1) ans1++;//只出现一次的因子不会重复，因此不影响全排列
		ll ans2 = f(ans1);
		for(i=0;i<t && prime[i]*prime[i]<=m;i++)
		{
			if(num[prime[i]])
			{
				ans2 /= f(num[prime[i]]);
			}
		}
		if(ans1==0) ans1 = 1;
		printf("%d %lld\n",ans1,ans2);
	}
}