#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
struct Block
{
	int h,num,limit;
}block[405];
int n;
bool cmp(Block x,Block y)
{
	return x.limit<y.limit;
}
int dp[40005];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++) 
	{
		scanf("%d %d %d",&block[i].h,&block[i].limit,&block[i].num);
	}
	sort(block+1,block+n+1,cmp);
	int ans = 0;
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=block[i].limit;j++)
		{
			if(dp[j]>=0) dp[j] = block[i].num;
			else if(j>=block[i].h && dp[j-block[i].h]>=1) 
			{
				dp[j] = dp[j-block[i].h] - 1;
				ans = max(ans,j);
			}
			else dp[j] = -1;
		}
	}
	printf("%d\n",ans);

}
/*
3
4 10 3
5 17 2
9 8 1

5
3 10 1
5 11 3
2 2 8
2 3 1
1 5 4
*/