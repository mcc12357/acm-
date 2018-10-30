#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
struct aa
{
	int x;
	int y;
};
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	aa a[201];
	_int64 f[201][201],res[201][201];
	for(i=0;i<n;i++) for(j=0;j<n;j++) res[i][j] = 1;
	for(i=0;i<n;i++) {scanf("%d %d",&a[i].x,&a[i].y);res[i][i] = a[i].x * a[i].y;}
	for(i=0;i<n;i++)
		for(j=i;j<n;j++) {f[i][j] = a[i].x * a[j].y;}
	for(i=0;i<n-1;i++) res[i][i+1] = res[i][i] * res[i+1][i+1];
	for(i=2;i<=n;i++)
		for(j=0;j+i<n;j++)
		{
			int r = i + j;
			res[j][r] = res[j][r-1] * res[r][r] * f[j][r-1];
			if(res[j][r]>res[j][j] * res[j+1][r] * f[j+1][r]) res[j][r] = res[j][j] * res[j+1][r] * f[j+1][r];
			for(k=j+1;k<r;k++)
			{
				if(res[j][r]>res[j][k] * res[k+1][r] * f[j][k] * f[k+1][r]) res[j][r] = res[j][k] * res[k+1][r] * f[j][k] * f[k+1][r] ;
			}
		}
	printf("%I64d\n",res[0][n-1]);
	return 0;
}