#include<iostream>
using namespace std;
#include<stdio.h>
typedef _int64 ll;
ll dp[1000005];
int main()
{
	int n;
	int i;
	dp[1] = 1;
	dp[2] = 2;
	scanf("%d",&n);
	for(i=3;i<=n;i++) 
	{
		if(i%2==0)
		{
			dp[i] = (dp[i-2] + dp[i/2]) % 1000000000;
		}
		else dp[i] = dp[i-1];
	}
	printf("%I64d\n",dp[n]);
	return 0;
}