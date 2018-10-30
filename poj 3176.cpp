#include<iostream>
using namespace std;
#include<stdio.h>
int a[400][400];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i,j;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=2;i<=n;i++) a[i][1] += a[i-1][1];
		for(i=2;i<=n;i++)
		{
			for(j=2;j<=i;j++)
			{
				a[i][j] += max(a[i-1][j-1],a[i-1][j]);
			}
		}
		int res = 0;
		for(i=1;i<=n;i++) res = max(res,a[n][i]);
		printf("%d\n",res);
	}
	return 0;
}