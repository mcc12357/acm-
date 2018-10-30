#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n,m;
int a[105];
int sum[105];
int main()
{
	scanf("%d %d",&n,&m);
	int i,j;
	sum[0] = 0;
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	int res = 0;
	int a,b;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		if(sum[b]-sum[a-1]>=0) res += sum[b]-sum[a-1];
	}
	printf("%d\n",res);
}