#include<iostream>
using namespace std;
#include<stdio.h>
/*һ��n*m���1��ʾ����ط�������ֲ��0��������ط�������ֲ��ֲ����ֲ��������������ֲ�ﲻ�����ڣ����������У����ʹ��м�����ֲ���������ҵ�ʲô������ʱ��Ϊ��һ�ַ����� 
����˼·�� 
��ֲ��1��ʾ������ֲ��0��ʾ��ÿһ�е�����Ϳ�����һ����������state���洢��state�ķ�Χ�� [0 ~ 1<< state). 
dp[i][state]��ʾ��i��״̬Ϊstate�������������������Ŀ�� 
״̬ת�Ʒ���Ϊ��dp[i][state] += dp[i-1][pre_state];���state��pre_state�����������������������������Ҳ����ڣ����²����ڡ���ô ��i��״̬Ϊstate�����Ϊ��i-1����������������״̬Ϊpre_state��Ӷ��ɡ� 
���Ĵ�Ϊ���һ������״̬���������Ӷ��á�*/
#include<string.h>
int dp[15][1<<15];//dp[i][j]��ʾ��i�з�j�������������
int is[15][15];
int n,m;
typedef  _int64 ll;
const int mod = 1e8;
int judge(int x,int state)
{
	if(state & (state<<1)) return 0;
	int i;
	for(i=1;i<=m;i++)//�����Ϊ0�ĸ��ӷ���ֲ��Ҳ�ǲ��Ϸ���
	{
		if(!is[x][i])
		{
			if(((1<<(m-i)) & state)) return 0;//ע���ж��Ƿ�Ϊ0��λ�÷���ֲ��ʱ�������iλΪ0����(1<<m-i)&state�����жϡ�
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
		for(i=1;i<=n;i++)//���н���ö��
		{
			for(j=0;j<(1<<m);j++)//��ÿһ�н���ö��
			{
				if(judge(i,j))//�жϵ�ǰ���Ƿ���������
				{
					for(k=0;k<(1<<m);k++)//ö����һ�зŷ�
					{
						if((j&k)==0) dp[i][j] += dp[i-1][k];//��ǰ������һ��һ������ж�
					}
				}
				if(i==n) ans = (ans + dp[i][j]) % mod;//����n�н�����dp[n][j]��Ӽ�Ϊ���
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}