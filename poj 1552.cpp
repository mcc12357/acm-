#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int a[20];
int is[100];
int main()
{
	while(~scanf("%d",&a[0]) && a[0]!=-1)
	{
		memset(is,0,sizeof(is));
		is[a[0]] = 1;
		int k = 1;
		while(1)
		{
			scanf("%d",&a[k]);
			if(a[k]==0) break;
			is[a[k]] = 1;
			k++;
		}
		int res = 0;
		int i;
		for(i=0;i<k;i++) 
		{
			if(a[i]<50 && is[a[i]*2]) res++;
		}
		printf("%d\n",res);

	}
}