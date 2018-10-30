#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<string.h>
double dp[100000005];
//int is[100000005];
int a[15];
int main()
{
	int n;
	double p,q;
	bool flag;
	while(~scanf("%d %lf",&n,&p))
	{
		//memset(dp,0,sizeof(dp));
		//memset(is,0,sizeof(is));
		flag = false;
		q = 1 - p;
		int i;
		for(i=0;i<=100000000;i++) dp[i] = 1;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			dp[a[i]] = 0;
			if(i>0 && a[i]-a[i-1]==1) flag = true;
		}
		if(flag) printf("0.0000000\n");
		else
		{
			dp[0] = dp[1] = 1;
			for(i=2;i<=a[n-1]+1;i++) if(dp[i]) dp[i] = q * dp[i-2] + p * dp[i-1];
			printf("%.7f\n",dp[a[n-1]+1]);
		}

	}
}