#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef long long ll;
ll dp[1010][10010];
const int mod = 1e9 + 7;
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	dp[0][0] = 1;
	for(i=1;i<=n;i++)
	{
		for(j=9000;j>=0;j--)
		{
			for(k=0;k<=9;k++)
			{
				if(j-k<0) break;
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;
			}
		}
	}
	ll ans = 0;
	if(n==1) printf("9\n");
	else
	{
		for(i=0;i<=9000;i++)
		{
			if(dp[n][i]) ans = (ans + dp[n][i] * (dp[n][i]-dp[n-1][i]) ) % mod;
		}
		printf("%lld\n",(ans+mod)%mod);
	}
}