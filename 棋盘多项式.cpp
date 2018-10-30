#include<iostream>
using namespace std;
#include<algorithm>
#include<stdio.h>
const int N = 8;
int b[N+1],w[N+1],r_b[N+1][65],r_w[N+1][65];
void init(int n)
{
	int i;
	if(n%2==0)
	{
		for(i=1;i<n-1;i+=2) b[i] = i + 1;
		for(i=2;i<n-1;i+=2) b[i] = i;
		b[n-1] = n;
		for(i=1;i<n-1;i+=2) w[i] = i;
		for(i=2;i<n-1;i+=2) w[i] = i - 1;
		w[n-1] = n - 1;
	}
	if(n%2)
	{
		for(i=1;i<n;i+=2) b[i] = i;
		for(i=2;i<n;i+=2) b[i] = i - 1;
		b[n] = n;
		for(i=1;i<n;i+=2) w[i] = i + 1;
		for(i=2;i<n;i+=2) w[i] = i;
	}
}
void cal(int n,int k,int c[N+1],int r[N+1][65])
{
	int i,j;
	for(i=0;i<=n;i++) r[i][0] = 1;
	for(i=1;i<=k;i++) r[0][i] = 0;
	for(i=1;i<=n;i++)
		for(j=1;j<=c[i];j++) r[i][j] = r[i-1][j] + r[i-1][j-1] * (c[i]-j+1);
}
int main()
{
	int i,j,n,k,ans;
	while(scanf("%d %d",&n,&k)!=EOF || n && k)
	{
		init(n);
		if(n%2==0)
		{
			cal(n-1,k,b,r_b);
			cal(n-1,k,w,r_w);
			ans = 0;
			for(i=0;i<=k;i++) ans += r_b[n-1][i] * r_w[n-1][k-i];
			printf("%d\n",ans);
		}
		else 
		{
			cal(n,k,b,r_b);
			cal(n,k,w,r_w);
			ans = 0;
			for(i=0;i<=k;i++) ans += r_b[n][i] * r_w[n][k-i];
			printf("%d\n",ans);
		}
		
		
	}
	return 0;
}