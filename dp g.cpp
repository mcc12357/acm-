#include<iostream>
using namespace std;
#include<stdio.h>
long long dp[105][105];
int data[105];
int n;
const int inf = 0x3f3f3f3f;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	scanf("%d",&n);
	int i,j,k,len;
	for(i=0;i<n;i++) scanf("%d",&data[i]);
	for(i=0;i+1<n;i++) dp[i][i+1] = 0;
	for(i=0;i<n;i++) dp[i][i] = 0;
	for(i=0;i+2<n;i++) dp[i][i+2] = data[i] * data[i+1] * data[i+2];
	long long tm;
	for(len=3;len<n;len++)
	{
		for(i=0;i<n;i++)
		{
			int j = i + len;
			if(j>=n) break;
			tm = inf;
			for(k=i+1;k<j;k++) 
			{
				tm = min(tm,dp[i][k]+dp[k][j]+data[k]*data[i]*data[j]);
			}
			dp[i][j] = tm;
		}
	}
	printf("%lld\n",dp[0][n-1]);

}