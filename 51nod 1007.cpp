#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int a[110],dp[10010];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int sum = 0;
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	dp[0] = 1;
	for(i=0;i<n;i++)
	{
		for(j=sum;j>=0;j--)
		{
			if(j-a[i]>=0 && dp[j-a[i]]) dp[j] = 1;
		}
	}
	for(i=sum/2;i>=0;i--)
	{
		if(dp[i]) break;
	}
	printf("%d\n",sum - 2 * i);
}