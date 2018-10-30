#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
int dp[25][4];
void init()
{
	int i;
	memset(dp,0,sizeof(dp));
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 10;
	dp[2][0] = 0;
	dp[2][1] = 10;
	dp[2][2] = 1;
	dp[2][3] = 100;
	for(i=3;i<=17;i++)
	{
		dp[i][0] = 10 * dp[i-1][0] + dp[i-1][2];
		dp[i][1] = dp[i-1][3];
		dp[i][2] = dp[i-1][1];
		dp[i][3] = 10 * dp[i-1][3] - dp[i-1][2];
	}
}
_int64 solve(_int64 x)
{
	_int64 sum = x;
	int a[20];
	int i=1;
	while(x)
	{
		a[i++] = x % 10;
		x /= 10;
	}
	int len = i - 1;
	if(len<3) return 0;
	if(len==3)
	{
		if(a[len]>5 || a[len]==5 && (a[len-1]>2||(a[len-1]==2&&a[len-2]>=1))) return 1;
		else return 0;
	}
	a[i] = 0;
	a[i+1] = 0;
	_int64 ans = 0;
	bool flag = false;	
	/*{
		_int64 x = 1;
		//ans += a[len] * dp[len-1][0] + dp[len-1][2];
		for(i=len;i>=1;i--)
		{
			ans += a[i] * dp[i-1][0];
			if(flag) x *= a[i];
			if(!flag && a[i]>5) ans += dp[i-1][2];
			if(!flag && a[i]>2 && a[i+1]==5) ans += dp[i-1][1];
			if(!flag && a[i]>1 && a[i+1]==2 && a[i+2]==5) ans += (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3]);
			if(!flag && a[i]==1 && a[i+1]==2 && a[i+2]==5) flag = true;
		}
		if(flag) ans += x;
	}*/
	for(i=len;i>=1;i--)
	{
		ans += dp[i-1][0] * a[i];
		if(flag) ans += dp[i-1][3] * a[i];
		else 
		{
			if(a[i]>5) ans += dp[i-1][2];
			if(a[i+1]==5 && a[i]>2) ans += dp[i-1][1];
			if(a[i+2]==5 && a[i+1]==2 && a[i]==1) flag = true;
		}
	}
	if(flag) ans ++;
	return ans;
	
}
int main()
{
	_int64 m,n;
	while(~scanf("%I64d %I64d",&m,&n))
	{
		if(m>n) swap(m,n); 
		init();
		printf("%I64d\n",solve(n)-solve(m-1));
	}
	return 0;
}