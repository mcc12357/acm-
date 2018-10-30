#include<iostream>
#include<stdio.h>
using namespace std;
#include<string.h>
int main()
{
	int n,i,j,sum;
	char win[1010][20],lose[1010][20];
	int res[1010];
	while(scanf("%d",&n)!=EOF && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s%s",win[i],lose[i]);
			res[i]=1;
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(strcmp(win[i],lose[j])==0) res[i]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n && i!=j;j++)
			{
				if(strcmp(win[i],win[j])==0) res[j]=0;
			}
		}
		sum=0;
		for(i=0;i<n;i++) sum+=res[i];
		if(sum==1) printf("Yes\n");
		else printf("No\n");
	}
}