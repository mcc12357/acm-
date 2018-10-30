#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int a[20],dp[1<<20];
int main()
{
	int m,n;
	int i,j;
	scanf("%d %d",&m,&n);//mÍ·Å££¬n¸ö¹È²Ö
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(i=1;i<=m;i++)
	{
		int k,p;
		scanf("%d",&k);
		for(j=0;j<k;j++) scanf("%d",&a[j]);
		for(j=(1<<n)-1;j>=0;j--)
		{
			for(p=0;p<k;p++)
			{
				if((j>>(n-a[p])&1) && dp[(j-(1<<(n-a[p])))] && (j-(1<<(n-a[p])))>=0) dp[j] += dp[(j-(1<<(n-a[p])))];
			}
		}
	}
	int res = 0;
	for(i=0;i<1<<n;i++) 
	{
		int num = 0;
		for(j=0;j<n;j++) if((i>>j)&1) num++;
		if(num==m) res += dp[i];
	}
	printf("%d\n",res);
}