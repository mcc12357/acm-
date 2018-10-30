#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int dp[1001][1001];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char a[1001],b[1001];
		scanf("%s",a);
		scanf("%s",b);
		int i,j;
		memset(dp,0,sizeof(dp));
		int lena = strlen(a);
		int lenb = strlen(b);
		for(i=0;i<lena;i++)
		{
			for(j=0;j<lenb;j++)
			{
				
				if(a[i]==b[j]) dp[i+1][j+1] = dp[i][j] + 1;//如果用dp[i][j] = dp[i-1][j-1] + 1,则还需要保证i-1,j-1均大于0，而且结果会小1。
				if(a[i]!=b[j]) dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);

			}
		}
		cout << dp[lena][lenb] << endl;
	}
}