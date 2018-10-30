#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
_int64 dp[25][25],a[25][25];
_int64 max(_int64 x,_int64 y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		_int64 n;
		int m;
		scanf("%I64d %d",&n,&m);
		int temp[25];
		int i,j,q,k=0;
		while(n)
		{
			temp[k++] = n % 10;
			n /= 10;
		}
		k--;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(i=0;i<=k;i++)//i表示区间长度
		{
			for(j=0;j+i<=k;j++)
			{
				_int64 p = 1;
				int r = j + i;
				for(q=j;q<=r;q++)
				{
					a[j][r] += p * temp[q];
					p *= 10;
				}
			}
		}
		for(i=0;i<=k;i++) dp[i][0] = a[0][i];
		//printf("%I64d\n",dp[i][0]);
		for(j=1;j<=m-1;j++)
		{
			for(i=0;i<=k;i++)
			{
				int p;
				for(p=0;p<i;p++) dp[i][j] = max(dp[i][j],dp[p][j-1]*a[p+1][i]);
			}
		}
		printf("%I64d\n",dp[k][m-1]);
	}
	return 0;
}