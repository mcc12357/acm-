#include<iostream>
using  namespace std;
#include<string.h>
#include<stdio.h>
int a[101][101],res[101][101],m,n;
int max(int p,int q)
{
	if(p>q) return p;
	else return q;
}
int dp(int x,int y)
{
	if(a[x-1][y]>a[x][y] && x-1>=0) res[x][y] = max(res[x][y],dp(x-1,y)+1);
	if(a[x+1][y]>a[x][y] && x+1<m) res[x][y] = max(res[x][y],dp(x+1,y)+1);
	if(a[x][y-1]>a[x][y] && y-1>=0) res[x][y] = max(res[x][y],dp(x,y-1)+1);
	if(a[x][y+1]>a[x][y] && y+1<n) res[x][y] = max(res[x][y],dp(x,y+1)+1);
	return res[x][y];
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> m >> n;
		int i,j;
		for(i=0;i<m;i++) for(j=0;j<n;j++) {cin >> a[i][j];res[i][j] = 1;}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				res[i][j] = dp(i,j);
			}
		int resmax = res[0][0];
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(res[i][j]>resmax) resmax = res[i][j];
			}
		printf("%d\n",resmax);
	}
	return 0;
}