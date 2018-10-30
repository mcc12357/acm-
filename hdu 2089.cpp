#include<iostream>
using namespace std;
#include<stdio.h>
int dp[8][3];
void init()
{
	dp[0][0] = 1;
	int i;
	for(i=1;i<=6;i++)
	{
		dp[i][0] = 9 * dp[i-1][0] - dp[i-1][1];
		dp[i][1] = dp[i-1][1];
		dp[i][2] = 10 * dp[i-1][2] + dp[i-1][1] + dp[i-1][0];
	}
}
void solve(int r)
{
	int i,j;
	for(i=)
}
int main()
{

}