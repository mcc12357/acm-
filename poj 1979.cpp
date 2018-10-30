#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
char a[25][25];
int res,m,n;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void dfs(int x,int y)
{
	int i;
	res++;
	a[x][y] = '#';
	for(i=0;i<4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if(a[nx][ny]!='#') dfs(nx,ny);
	}
}
int main()
{
	while(~scanf("%d %d",&n,&m) && (m+n))
	{
		int i,j,sx,sy;
		res = 0;
		for(i=0;i<=20;i++)
			for(j=0;j<=20;j++) a[i][j] = '#';
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++) 
			{
				cin >> a[i][j];
				if(a[i][j]=='@') 
				{
					sx = i;
					sy = j;
				}
			}
		for(i=1;i<=n;i++) {a[0][i] = '#';a[m+1][i] = '#';}
		for(i=1;i<=m;i++) {a[i][0] = '#';a[i][n+1] = '#';}
		dfs(sx,sy);
		printf("%d\n",res);		
	}
	return 0;
}