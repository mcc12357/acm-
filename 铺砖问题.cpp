#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
int dp[2][1<<15];
int color[15][15];
const int M = 10000007;
int main()
{
	int m,n;
	char tm;
	int i,j,used;
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<n;i++)
		for(j=0;j<m;j++) 
		{
			cin>>tm;
			if(tm=='.') color[i][j] = 0;
			else color[i][j] = 1;
		}
	int *crt = dp[0],*next = dp[1];
	crt[0] = 1;
	for(i=n-1;i>=0;i--)
	{
		for(j=m-1;j>=0;j--)
		{
			for(used=0;used< 1<<m;used++)
			{
				if((used >> j & 1) || color[i][j])
				{
					next[used] = crt[used & ~(1 << j)];
				}
				else
				{
					int res = 0;
					if(j+1<m && !(used>>(j+1)&1) && !color[i][j+1])
					{
						res += crt[used | 1 << (j+1)];
					}
					if(i+1<n && !color[i+1][j])
					{
						res += crt[used | 1<<j];
					}
					next[used] = res % M;
				}
			}
			swap(crt,next);
		}
	}
	printf("%d\n",crt[0]);
}