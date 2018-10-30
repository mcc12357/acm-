#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
#define maxn 1010
int prime[maxn];
bool isprime[maxn];
int sieve(int n)
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
int main()
{
	 int n;
	 scanf("%d",&n);
	 int p = sieve(n);
	 int i,j;
	 int ans = 0;
	 for(i=0;i<p;i++)
	 {
		for(j=2;j<=10;j++)
		{
			if(pow(prime[i],j)<=n) ans++;
		}
	 }
	 printf("%d\n",ans+p);
}