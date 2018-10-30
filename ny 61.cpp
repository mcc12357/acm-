#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int dp[105][55][55];
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int p,q;//p行q列
		scanf("%d %d",&p,&q);
		int i,k,m,j;
		int a[55][55];
		for(i=1;i<=p;i++)
			for(j=1;j<=q;j++) scanf("%d",&a[i][j]);
		int t = p - 1 + q - 1;//总步数
		memset(dp,0,sizeof(dp));
		for(k=1;k<=t;k++)
		{
			
			for(i=0;i<=q-1;i++)
			{
				if(k<i) continue;
				for(m=0;m<=q-1;m++)
				{
					if(k<m) continue;
					if(i==m && (k!=t || i!=q-1 || m!=q-1)) continue;
					if(i==0)
					{
						if(k+1>p) continue;
						dp[k][i][m] = max(dp[k-1][i][m-1],dp[k-1][i][m]) + a[k+1][1] + a[k-m+1][1+m];
					}
					else if(m==0) 
					{
						if(k+1>p) continue;
						dp[k][i][m] = max(dp[k-1][i-1][m],dp[k-1][i][m]) + a[k+1][1] + a[k-i+1][1+i];
					}
					else
					{
						if(k-i+1>p || k-m+1>p) continue;
						dp[k][i][m] = max(max(max(dp[k-1][i-1][m],dp[k-1][i-1][m-1]),dp[k-1][i][m-1]),dp[k-1][i][m]) + a[k-i+1][1+i] + a[k-m+1][1+m];
					}
				}
			}
		}
		printf("%d\n",dp[t][q-1][q-1]);

	}
	return 0;
}