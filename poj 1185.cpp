//ֻҪÿ�д�������༴����ͼ���������
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
int is[150][15];
int dp[110][(1<<10)+5][(1<<10)+5];
int n,m,t = 0;
int can[100];//��can����ÿ�����������Ľ⣬���Թ��ƽ����������100�����������Ԥ�����tel
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
int check(int x,int state)//�ж�state�Ƿ�����������������������������1�ĸ���
{
	int cnt = 0;
	int i;
	if(state>=pow((int)2,m)) return -1;
	for(i=1;i<=m;i++)
	{
		if((1<<(i-1))&state) cnt++;//����state��1�ĸ���
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
			int cnt = check(i,can[j]);//�жϵ�ǰ���Ƿ���������
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
								if(!(can[j]&can[q])) now = max(now,dp[i-1][can[k]][can[q]]);//�ж�i-2�к͵�i���Ƿ��������
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