#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 510
typedef _int64 ll;
int m,n;
const int mod = 1000000007;
ll dp[2][maxn][maxn];
char map[maxn][maxn];
int main()
{
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=1;i<=m;i++) 
		for(j=1;j<=n;j++) cin>>map[i][j];
	int step;
	dp[0][1][m] = (map[1][1]==map[m][n]);
	int cur = 0;
	for(step=1;step<=(m+n-2)/2;step++)
	{
		int x1,x2;
		cur ^= 1;
		/*for (i = 0; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                dp[cur][i][j] = 0;
            }
        }*/
		for(x1=1;x1<=m && x1-1<=step;x1++)
		{
			for(x2=m;x2>=1 && m-x2<=step;x2--)
			{
				int y1 = 1 + step - (x1 - 1);
				int y2 = n - (step - (m - x2));
				dp[cur][x1][x2] = 0;
				if(map[x1][y1]!=map[x2][y2]) continue;
				dp[cur][x1][x2] = (dp[cur][x1][x2] + dp[cur^1][x1][x2]) %  mod;
				dp[cur][x1][x2] = (dp[cur][x1][x2] + dp[cur^1][x1][x2+1]) % mod;
				dp[cur][x1][x2] = (dp[cur][x1][x2] + dp[cur^1][x1-1][x2]) % mod;
				dp[cur][x1][x2] = (dp[cur][x1][x2] + dp[cur^1][x1-1][x2+1]) % mod;
			}
		}
	}
	ll ans = 0;
	for(i=1;i<=m;i++) ans = (ans + dp[cur][i][i]) % mod;
	if((m+n)%2)
	{
		for(i=1;i<m;i++) ans = (ans + dp[cur][i][i+1]) % mod;
	}
	printf("%I64d\n",ans);
}