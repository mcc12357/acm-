#include<iostream>
using namespace std;
int main()
{
	int m,n,dp[21][21],i,j;
	memset(dp,0,sizeof(dp));
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		dp[1][2]=0;
		for(i=0;i<m;i++) dp[1][i]=0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++) 
			{
				if(i<j) {dp[i][j] = 0;continue;}
				dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
			}
			printf("%d\n",dp[m][n]);
	}
}