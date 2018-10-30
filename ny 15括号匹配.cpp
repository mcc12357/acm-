#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
const int aa = 1<<10; 
int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[105];
		int dp[105][105];
		scanf("%s",a);
		int len = strlen(a);
		int i,j,k;
		for(i=0;i<len;i++) dp[i][i] = 1;
		for(i=0;i<len-1;i++) 
		{
			dp[i][i+1] = 0;
		}
		for(i=1;i<=len;i++)
		{
			for(j=0;j+i<len;j++)
			{
				int r = i + j;
				dp[j][r] = aa;
				if(a[j]=='(' && a[r]==')' || a[j]=='[' && a[r]==']')
				{
					if(j+1>r-1) {dp[j][r] = 0;continue;}
					dp[j][r] = min(dp[j+1][r-1],dp[j][r]);
				}
				else if(a[j]==')' || a[j]==']')
				{
					dp[j][r] = min(dp[j+1][r],dp[j][r]) + 1;
				}
				else if(a[r]=='(' || a[r]=='[') dp[j][r] = min(dp[j+1][r],dp[j][r]) + 1;
				for(k=j;k<r;k++) dp[j][r] = min(dp[j][r],dp[j][k]+dp[k+1][r]);
			}
		}
		printf("%d\n",dp[0][len-1]);
	}
	return 0;
}