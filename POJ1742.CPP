#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int n,m;
int a[105];
int dp[100005];
int main()
{
	while(~scanf("%d %d",&n,&m) &&(m||n))
	{
		int i,j,temp;
		memset(dp,-1,sizeof(dp));
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		dp[0] = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			for(j=0;j<=m;j++)
			{
				if(dp[j]!=-1) dp[j] = temp;
				if(dp[j]==-1)
				{
					if(j>=a[i] && dp[j-a[i]]!=-1) dp[j] = dp[j-a[i]] - 1;//ע��Ҫ��֤j>=a[i]����������Խ��
				}
			}
		}
		int res = 0;
		for(i=1;i<=m;i++) if(dp[i]!=-1) res++;
		printf("%d\n",res);
	}
	return 0;
}