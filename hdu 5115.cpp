#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef long long ll;
const ll inf = 0xfffffff;
ll min(ll x,ll y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	int num;
	for(num=1;num<=t;num++)
	{
		int n;
		scanf("%d",&n);
		int a[205],b[205];
		int i,j,k;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) scanf("%d",&b[i]);
		ll dp[205][205];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) dp[i][j] = inf;
		dp[0][0] = a[0] + b[1];
		dp[n-1][n-1] = a[n-1] + b[n-2];
		for(i=1;i<=n-2;i++) dp[i][i] = a[i] + b[i-1] + b[i+1];
		for(i=1;i<n-1;i++)
		{
			{
				j = 0;
				int r = i + j;
				for(k=j+1;k<r;k++)
				{
					if(r==n-1) continue;
					dp[j][r] = min(dp[j][r],dp[j][k-1]+dp[k+1][r]+a[k]+b[r+1]);	
				}
				dp[j][r] = min(dp[j][r],dp[j+1][r]+a[j]+b[r+1]);
				dp[j][r] = min(dp[j][r],dp[j][r-1]+a[r]+b[r+1]);
			}
			
			for(j=1;i+j<n-1;j++)
			{
				int r = i + j;
				for(k=j+1;k<r;k++)
				{
					dp[j][r] = min(dp[j][r],dp[j][k-1]+dp[k+1][r]+a[k]+b[j-1]+b[r+1]);	
				}
				dp[j][r] = min(dp[j][r],dp[j+1][r]+a[j]+b[j-1]+b[r+1]);
				dp[j][r] = min(dp[j][r],dp[j][r-1]+a[r]+b[j-1]+b[r+1]);
			}
			{
				int r = n - 1;
				j = r - i;
				for(k=j+1;k<r;k++)
				{
					if(j==0) continue;
					dp[j][r] = min(dp[j][r],dp[j][k-1]+dp[k+1][r]+a[k]+b[j-1]);	
				}
				dp[j][r] = min(dp[j][r],dp[j+1][r]+a[j]+b[j-1]);
				dp[j][r] = min(dp[j][r],dp[j][r-1]+a[r]+b[j-1]);
			}
		}
		for(k=1;k<n-1;k++)
		{
			dp[0][n-1] = min(dp[0][n-1],dp[0][k-1]+dp[k+1][n-1]+a[k]);
		}
		dp[0][n-1] = min(dp[0][n-1],a[0]+dp[1][n-1]);
		dp[0][n-1] = min(dp[0][n-1],dp[0][n-2]+a[n-1]);
		printf("Case #%d: %lld\n",num,dp[0][n-1]);
	}
}