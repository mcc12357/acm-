#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int dp[110][110];
int judge(char a,char b)
{
	if(a=='('&&b==')')
		return 1;
	if(a=='['&&b==']')
		return 1;
	return 0;
}
int main()
{
	char s[110];
	while(scanf("%s",s+1)!=EOF)
	{
		if(strcmp(s+1,"end")==0)
			break;
		int len=strlen(s+1);
		memset(dp,0,sizeof(dp));
		for(int l=1;l<=len;l++)
		{
			for(int i=1;i+l-1<=len;i++)
			{
				int j=i+l-1;
				if(judge(s[i],s[j]))
					dp[i][j]=dp[i+1][j-1]+1;
				for(int k=i;k<=j;k++)
					dp[i][j]=max(dp[i][k]+dp[k+1][j],dp[i][j]);

			}
		}
		cout<<2*dp[1][len]<<'\n';
	}
	return 0;
}