#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int max(int m,int n)
{
	if(m>n) return m;
	else return n;
}
const int _max = 30001;
int money,num,pr[26],im[26],dp[26][_max];
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int i,j;
		memset(dp,0,sizeof(dp));
		cin >> money >> num;
		for(i=0;i<num;i++)
		{
			cin >> pr[i] >> im[i];
		}
		for(i=num-1;i>=0;i--)
		{
			for(j=0;j<=money;j++)
			{
				if(j<pr[i])
				{
					dp[i][j] = dp[i+1][j];
				}
				else 
				{
					dp[i][j] = max(dp[i+1][j],dp[i+1][j-pr[i]] + im[i]*pr[i]);
				}
			}
		}
		cout << dp[0][money] <<endl;

	}
	return 0;
}