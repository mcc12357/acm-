#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k,l,sum;
	while(scanf("%d",&n)!=EOF)
	{
	sum=0;
	int dp[101][4][4];
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(i==j) dp[0][i][j] = 1;
			else dp[0][i][j] = 0;
		}

	for(j=1;j<=n;j++)
		for(i=0;i<4;i++)
		{
			dp[j][i][0] = (dp[j-1][i][0] + dp[j-1][i][1] + dp[j-1][i][3])%9937;
			dp[j][i][1] = (dp[j-1][i][0] + dp[j-1][i][1] + dp[j-1][i][2])%9937;
			dp[j][i][2] = (dp[j-1][i][1] + dp[j-1][i][2] + dp[j-1][i][3])%9937;
			dp[j][i][3] = (dp[j-1][i][0] + dp[j-1][i][2] + dp[j-1][i][3])%9937;
		}//dp[j][i][0]表示第J天i号机器人到达0号毯子所有的方法数

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				for(l=0;l<4;l++)
				{
					if(i==j || i==k || i==l || j==k || j==l || k==l) continue;
					sum+=(((dp[n][0][i]*dp[n][1][j]%9937)*dp[n][2][k]%9937)*dp[n][3][l]%9937);
					sum%=9937;
				}

	printf("%d\n",sum);
	}


}