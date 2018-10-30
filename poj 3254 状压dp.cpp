#include<iostream>
using namespace std;
#include<stdio.h>
/*一块n*m的田，1表示这个地方可以种植，0代表这个地方不能种植。植物种植还必须满足两株植物不能相邻（横竖都不行）。问共有几种种植方法，而且当什么都不种时认为是一种方法。 
解题思路： 
种植用1表示，不种植用0表示。每一行的情况就可以用一个二进制数state来存储。state的范围是 [0 ~ 1<< state). 
dp[i][state]表示第i行状态为state的情况下满足条件的数目。 
状态转移方程为：dp[i][state] += dp[i-1][pre_state];这个state和pre_state必须满足意义所给的条件，即左右不相邻，上下不相邻。那么 第i行状态为state的情况为第i-1行所有满足条件的状态为pre_state相加而成。 
最后的答案为最后一行所有状态的情况和相加而得。*/
#include<string.h>
int dp[15][1<<15];//dp[i][j]表示第i行放j这种情况的种数
int is[15][15];
int n,m;
typedef  _int64 ll;
const int mod = 1e8;
int judge(int x,int state)
{
	if(state & (state<<1)) return 0;
	int i;
	for(i=1;i<=m;i++)//如果在为0的格子放了植物也是不合法的
	{
		if(!is[x][i])
		{
			if(((1<<(m-i)) & state)) return 0;//注意判断是否为0的位置放了植物时，如果第i位为0，将(1<<m-i)&state进行判断。
		}
	}
	return 1;
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		memset(dp,0,sizeof(dp));
		int i,j,k;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++) scanf("%d",&is[i][j]);
		dp[0][0] = 1;
		ll ans = 0;
		for(i=1;i<=n;i++)//对行进行枚举
		{
			for(j=0;j<(1<<m);j++)//对每一行进行枚举
			{
				if(judge(i,j))//判断当前行是否满足条件
				{
					for(k=0;k<(1<<m);k++)//枚举上一行放法
					{
						if((j&k)==0) dp[i][j] += dp[i-1][k];//当前行与上一行一起进行判断
					}
				}
				if(i==n) ans = (ans + dp[i][j]) % mod;//到第n行将所有dp[n][j]相加即为结果
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}