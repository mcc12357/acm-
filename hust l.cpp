#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
typedef long long ll;
#define maxn 100010
const int mod = 1000000007;
ll dp[maxn];
char s[maxn];
bool a[16];
int main()
{
	int t,count = 1;
	scanf("%d",&t);
	memset(a,0,sizeof(a));
	int i,j;
	for(i=0;i<=13;i++)
	{
		if(i==3 || i==5) continue;
		a[i] = true;
	}
	while(t--)
	{
		scanf("%s",s);
		memset(dp,0,sizeof(dp));
		int n = strlen(s);
		dp[0] = 1;
		dp[1] = 2;
		dp[2] = 4;
		int tm = 0,k = 1;
		for(i=3;i>=0;i--)
		{
			if(s[i]=='-') tm += k;
			k *= 2;
		}
		if(a[tm]) dp[3] = 8;
		else dp[3] = 7;
		for(i=4;i<n;i++)
		{
			tm = 0;
			k = 1;
			for(j=i;i-j<4;j--)
			{
				if(s[j]=='-') tm += k;
				k *= 2;
			}
			dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;
			if(a[tm]) dp[i] = (dp[i] + dp[i-4]) % mod;
		}
		printf("Case #%d: %lld\n",count,dp[n-1]);
		count++;
	}
}