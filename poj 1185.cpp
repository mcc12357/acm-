//只要每行大炮数最多即整张图大炮数最多
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
int is[150][15];
int dp[110][(1<<10)+5][(1<<10)+5];
int n,m,t = 0;
int can[100];//用can保存每行满足条件的解，可以估计解个数不大于100，如果不进行预处理会tel
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
void init()
{
	int i;
	for(i=0;i<(1<<10);i++)
	{
		if(i&(i<<1) || i&(i<<2)) continue;
		can[++t] = i;
	}
	return ;
}
int check(int x,int state)//判断state是否满足条件，如果满足条件求出其中1的个数
{
	int cnt = 0;
	int i;
	if(state>=pow((int)2,m)) return -1;
	for(i=1;i<=m;i++)
	{
		if((1<<(i-1))&state) cnt++;//计算state中1的个数
		if(is[x][i]==0)
		{
			if((1<<(m-i))&state) return -1;
		}
	}
	return cnt;
}
int main()
{
	//freopen("duipai.out","r",stdin);
	init();
	scanf("%d %d",&n,&m);
	int i,j,k,q;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
        {
			char op;  scanf(" %c",&op);
            if( op =='P') is[i][j] = 1;
            else is[i][j] = 0;
        }
	int ans = 0,now;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=t;j++)
		{
			int cnt = check(i,can[j]);//判断当前行是否满足条件
			if(cnt!=-1)
			{
				for(k=1;k<=t;k++)
				{
					if(!(can[k]&can[j]))
					{
						dp[i][can[j]][can[k]] = cnt;
						now = 0;
						for(q=1;q<=t;q++)
						{
							if(i!=1)
							{
								if(!(can[j]&can[q])) now = max(now,dp[i-1][can[k]][can[q]]);//判断i-2行和第i行是否符合条件
							}
						}
					}
					dp[i][can[j]][can[k]] += now;
					if(i==n) ans = max(ans,dp[i][can[j]][can[k]]);
				}
			}

		}
	}
	printf("%d\n",ans);
	return 0;
}