#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
bool isprime[1000005];
int m;//m保存大于100000的最小素数
bool judge(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
void doprime()
{
	int i,j;
	for(i=1;i<=1000000;i++) isprime[i] = true;
	isprime[1] = false;
	for(i=2;i<=1000000;i++)
	{
		if(isprime[i])
		{
			for(j=2*i;j<=1000000;j+=i)
			{
				isprime[j] = false;
			}
		}
	}
}
void pjudge(int a)
{
	int i;
	for(i=0;;i++)
	{
		if(a+i<=m)
		{
			if(isprime[a-i])
			{
				printf("%d %d\n",a-i,i);
				return;
			}
			else if(isprime[a+i])
			{
				printf("%d %d\n",a+i,i);
				return;
			}
		}
		else 
		{
			printf("%d %d\n",m,m-a);
			return;
		}	
	}
}
int main()
{
	int i;
	for(i=1000000;;i++)
	{
		if(judge(i)) 
		{
			m = i;
			break;
		}
	}
	doprime();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a;
		scanf("%d",&a);
		pjudge(a);

	}
	return 0;
}