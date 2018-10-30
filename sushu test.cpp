#include<iostream>
using namespace std;
#include<stdio.h>
int prime[100000000];
bool isprime[100000005];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int sieve(int n)
{
	int p = 0;
	int i,j;
	for(i=0;i<=n;i++)
	{
		isprime[i] = true;
	}
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
int main()
{
	int num = sieve(100000000);
	int i;
	int tmax = -1;
	for(i=1;i<=num;i++) tmax = max(tmax,prime[i]-prime[i-1]);
	printf("%d\n",num);
}