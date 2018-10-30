#include<iostream>
using namespace std;
#include<algorithm>
#include<stdio.h>
long long dp[2][1<<15];
int main()
{
	int m,n;
	while(scanf("%d %d",&n,&m)!=EOF && n && m)
	{
		long long *crt = dp[0],*next = dp[1];
		crt[0] = 1;
		int i,j,used;
		for(i=n-1;i>=0;i--)
		{
			for(j=m-1;j>=0;j--)
			{
				for(used=0;used < 1 << m;used++)
				{
					if(used >> j & 1)
					{
						next[used] = crt[used & ~(1 << j)];
					}
					else 
					{
						long long res = 0;
						if(j+1<m && !(used>>(j+1)&1))
						{
							res += crt[used | 1 << (j+1)];
						}
						if(i+1<n)
						{
							res += crt[used | 1 << j];
						}
						next[used] = res;
					}
				}
				swap(crt,next);
			}
		}
		printf("%lld\n",crt[0]);
	}
	return 0;
}