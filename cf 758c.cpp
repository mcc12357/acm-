#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
int n,m,x,y;
ll k;
int main()
{
	scanf("%d %d %I64d %d %d",&n,&m,&k,&x,&y);
	if(n==1)
	{
		ll tm = k / m;
		ll tc = k - k / m;
		if(y<=tc)
		{
			printf("%I64d %I64d %I64d\n",(k-1)/m+1,k/m,(k-1)/m+1);
		}
		else 
		{
			printf("%I64d %I64d %I64d\n",(k-1)/m+1,k/m,k/m);
		}
	}
	else
	{
		if(k<=m)
		{
			if(y<=k)
			{
				printf("1 0 1\n");
			}
			else
			{
				printf("1 0 0\n");
			}
		}
		else
		{
			int tm = (n - 1) * m;
			ll tk = (k - m - 1) / tm;
			ll left = k - m - tm * tk;
			if(tk%2==0)
			{
				int kk = (x-1) * m + y;
				if(kk<=left) printf("%I64d %I64d %I64d\n",(k-m-1)/tm+1,(k-m)/tm,(k-m-1)/tm+1);
				else printf("%I64d %I64d %I64d\n",(k-m-1)/tm+1,(k-m)/tm,(k-m)/tm);
			}
			else
			{
				int kk = (x-1) * m + y;
				if(kk>=left) printf("%I64d %I64d %I64d\n",(k-m-1)/tm+1,(k-m)/tm,(k-m-1)/tm+1);
				else printf("%I64d %I64d %I64d\n",(k-m-1)/tm+1,(k-m)/tm,(k-m)/tm);
			}
		}
	}
}