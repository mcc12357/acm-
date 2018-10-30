#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int n,m;
char a[2005];
int cost[30];
int dp[2005][2005];
int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
int main()
{
	scanf("%d %d",&n,&m);
	int i,j,x,y;
	char t;
	getchar();
	for(i=0;i<m;i++) scanf("%c",&a[i]);
	for(i=0;i<n;i++)
	{
		cin>>t>>x>>y;
		cost[t-'a'] = min(x,y);
	}
	memset(dp,0,sizeof(dp));
	for(i=m-2;i>=0;i--)
	{
		for(j=i+1;j<m;j++)
		{
			if(a[i]==a[j]) dp[i][j] = dp[i+1][j-1];
			else dp[i][j] = min(dp[i+1][j]+cost[a[i]-'a'],dp[i][j-1]+cost[a[j]-'a']);
		}
	}
	printf("%d\n",dp[0][m-1]);
	return 0;

}