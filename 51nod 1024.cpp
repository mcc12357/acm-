#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 600
int dp[maxn][maxn];
int bit[20];
int num[maxn];
int num1[maxn];
int val[maxn];
void solve(int x,int y)
{
	int t = x;
	int k = 0;
	int i;
	for(i=2;i<=x;i++)
	{
		if(t%i==0)
		{
			while(t%i==0)
			{
				bit[k++] = i;
				t /= i;
			}
		}
	}
	bool flag = false;
	memset(num,0,sizeof(num));
	for(i=0;i<k;i++) num[bit[i]]++;
	int kk = 0;
	memset(num1,0,sizeof(num1));
	for(i=2;i<=x;i++)
	{
		if(num[i]) 
		{
			val[kk] = i;
			num1[kk] = num[i];
			kk++;
		}
	}
	for(i=1;i<kk;i++) 
	{
		if(num1[i-1]!=num1[i])
		{
			flag = true;
			break;
		}
	}
	if(flag) dp[x][y] = 1;
	else
	{
		int tm = 1;
		for(i=0;i<kk;i++) tm *= val[i];
		y *= num1[0];
		dp[tm][y] = 1;
	}
}
int main()
{
	int m,n,a,b,i,j;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			solve(a+i,b+j);
		}
	}
	int res = 0;
	for(i=0;i<maxn;i++)
		for(j=0;j<maxn;j++) if(dp[i][j]) res++;
	printf("%d\n",res);

}