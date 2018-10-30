#include<stdio.h>
#include<string.h>
int max(int m,int n)
{
	if(m>n) return m;
	else return n;
}
int main()
{
	char a[100],b[100];
	int dp[101][101],m,n,i,j,t=0;
	scanf("%s",a);
	m=strlen(a);
	scanf("%s",b);
	n=strlen(b);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) dp[i][j]=0;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
			if(a[i]!=b[j]) dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}
	for(i=0;i<m+1;i++)
		for(j=0;j<n+1;j++)
			t=max(t,dp[i][j]);

		printf("%d\n",t);
}