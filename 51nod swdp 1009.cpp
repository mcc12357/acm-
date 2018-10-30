#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
int dp[15][15];
int a[20];
ll dfs(int pos,int state,int flag)
{
	if(pos==-1) return state;
	if(flag && dp[pos][state]) return dp[pos][state];
	int m = flag?9:a[pos];
	int i;
	ll res = 0;
	for(i=0;i<=m;i++)
	{
		if(i==1) res += dfs(pos-1,state+1,flag|i<a[pos]);
		else res += dfs(pos-1,state,flag|i<a[pos]);
	}
	if(flag) dp[pos][state] = res;
	return res;

}
int main()
{
	int n;
	scanf("%d",&n);
	int len = 0;
	while(n)
	{
		a[len++] = n % 10;
		n /= 10;
	}
	ll res = dfs(len-1,0,0);
	printf("%I64d\n",res);
}