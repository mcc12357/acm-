#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n,a,b;
int hp[20];
//int dp[20][20];
int res = 2000;
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
void dfs(int x,int y,int i,int num)
{
	int tmin;
	if(x<0) tmin = 0;
	else tmin = x / b + 1;
	if(num>res) return ;
	if(i==n-2)
	{
		int tm = max(max(x/b,y/a),hp[n-1]/b) + 1;
		tm += num;
		if(tm<res)
		{
			res = tm;
		}
		return ;
	}
	int tmax = max(tmin,max(y/a,hp[i+1]/b)+1);
	int j;
	int ans = 2000;
	for(j=tmin;j<=tmax;j++)
	{
		//hp[i+1] -= b * j;
		//hp[i] -= a * j;
		dfs(y-a*j,hp[i+1]-b*j,i+1,num+j);
		//hp[i+1] += b * j;
		//hp[i] += a * j;
	}
}
int main()
{
	scanf("%d %d %d",&n,&a,&b);
	int i;
	for(i=0;i<n;i++) scanf("%d",&hp[i]);
	dfs(hp[0],hp[1],1,0);
	printf("%d\n",res);
}
/*
6
2 1
2 3 1 4 2 3
*/