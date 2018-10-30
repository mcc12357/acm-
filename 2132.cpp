#include<iostream>
using namespace std;
#include<stdio.h>
#include<cstring>
int main()
{
	_int64 a[100002],t,i,j;
	memset(a,0,sizeof(a));
	while(1)
	{
		scanf("%I64d",&t);
		if(t<0) break;
		a[1] = 1;
		if(a[t]!=0) printf("%I64d\n",a[t]);
		else 
		{
			for(i=1;i<=t;i++)
			{
				if(a[i]==0) break;
			}
			for(j=i;j<=t;j++)
			{
				if(j%3==0) a[j] = a[j-1] + j*j*j;
				else a[j] = a[j-1] + j;
			}
			printf("%I64d\n",a[t]);

		}
	}
	return 0;
}