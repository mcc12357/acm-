#include<iostream>
using namespace std;
#include<stdio.h>
int f[10005];
bool isprime[10005];
int min(int x,int y)
{
	if(x>y) return y;
	return x;
}
int main()
{
	int i,j;
	f[0] = 0;
	f[1] = 1;
	for(i=0;i<=10000;i++) isprime[i] = true;
	isprime[0] = isprime[1] = false;
	for(i=2;i<=10000;i++)
	{
		if(isprime[i])
		{
			for(j=2*i;j<=10000;j+=i) isprime[j] = false;
		}
	}
	for(i=2;i<=10000;i++)
	{
		f[i] = i;
		if(!isprime[i])
		{
			for(j=2;j*j<=i;j++)
			{
				if(i%j==0)
				{
					f[i] = min(f[i],f[j]+f[i/j]);
				}
			}
			f[i] = min(f[i-1]+1,f[i]);
		}
		else
		{
			f[i] = min(f[i-1]+1,f[i]);
		}
	}
	int t;
	while(~scanf("%d",&t))
	{
		printf("%d\n",f[t]);
	}
	return 0;
}