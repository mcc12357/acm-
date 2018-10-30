#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	int len1 = a.size();
	int len2 = b.size();
	a.reserve();
	b.reserve();
	int i,j,k;
	int dp[105][105];
	memset(dp,0,sizeof(dp));
	for(i=1;i<=len1;i++)
		for(j=1;j<=len2;j++)
		{
			dp[i][j] = dp[i-1][j-1];
			if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1] + 2;
			else
			{
				for(k=0;k<i;k++) dp[i][j] = max(dp[i][j],dp[k][j]-1);
				for(k=0;k<j;k++) dp[i][j] = max(dp[i][j],dp[i][k]-1);
			}
		}
	printf("%d\n",dp[len1][len2]);
}