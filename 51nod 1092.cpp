#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
char a[1010],b[1010];
int dp[1010][1010];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%s",a);
	int m = strlen(a);
	int i,j;
	for(i=0;i<m;i++)
	{
		b[i] = a[m-i-1];
	}
	bool flag1 = false,flag2 = false;
	for(i=0;i<m;i++)//注意dp的含义。因此初始化要注意
	{
		if(flag1) dp[0][i] = 1;
		if(flag2) dp[i][0] = 1;
		if(a[0]==b[i]) 
		{
			dp[0][i] = 1;
			flag1 = true;
		}
		if(b[0]==a[i]) 
		{
			dp[i][0] = 1;
			flag2 = true;
		}
	}
	for(i=1;i<m;i++)
	{
		for(j=1;j<m;j++)
		{
			if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	printf("%d\n",m-dp[m-1][m-1]);
}