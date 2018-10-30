#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
typedef long long ll;
int dp[25][4];
void init()
{
	int i;
	dp[0][3] = 1;
	dp[1][0] = 0;
	dp[1][1] = 0;
	dp[1][2] = 1;
	dp[1][3] = 10;
	for(i=2;i<=20;i++)
	{
		dp[i][0] = dp[i-1][0] * 10 + dp[i-1][1];
		dp[i][1] = dp[i-1][2];
		dp[i][2] = dp[i-1][3];
		dp[i][3] = dp[i-1][3] * 10 - dp[i-1][1];
	}
}
ll solve(ll x)
{
	int digit[25];
    int cnt = 0;
    while(x)
	{
        digit[++cnt] = x % 10;
        x /= 10;
    }
    digit[cnt+1] = 0;
	digit[cnt+2] = 0;
	//printf("cnt = %d\n",cnt);
    int flag=0;
    ll ans=0;
	int i;
	for(i=cnt;i>0;i--)
	{
		ans += digit[i]*dp[i-1][0];
		if(flag)
		{
			ans += digit[i] * dp[i-1][3];
		}
		else
		{
			if(digit[i]>5)
			{
				ans += dp[i-1][1];
			}
			if(digit[i]==1 && digit[i+1]==2 && digit[i+2]==5)
			{
				flag = 1;
			}

		}
	}
	return ans;
}
int main()
{
	ll m,n;
	init();
	while(~scanf("%lld %lld",&m,&n))
	{
		if(m>n) swap(m,n);
		printf("%lld\n",solve(n+1)-solve(m));
	}
}