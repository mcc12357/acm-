#include<iostream>
using namespace std;
#include<stdio.h>
long long gcd(long long x,long long y)
{
	if(y==1) return x;
	else return gcd(y,x%y);
}
int main()
{
	int t;
	while(t--)
	{
		long long q,p,res,tt;
		scanf("%I64d %I64d",&q,&p);
		int i,j;
		for(i=1;i<=q/2;i++)
		{
			res += (gcd(q-i,i) - 1);
			res %= p;
		}
		tt = ((q-1)*(q-2)/2)%p;
		tt -= res;
		tt = (tt+p)%p;
		printf("%I64d\n",tt);
		
	}
	return 0;
}