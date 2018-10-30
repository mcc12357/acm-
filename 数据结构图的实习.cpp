#include<iostream>
using namespace std;
#include<stdio.h>
char map[1000][1000];
int res,m,n,sx,sy;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void dfs(int x,int y)
{
	map[x][y] = '*';
	res++;
	int i;
	for(i=0;i<4;i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx>=0 && tx<m && ty>=0 && ty<n && map[tx][ty]=='#') dfs(tx,ty);
	}
}
int main()
{
	res = 0;
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='@')
			{
				sx = i;
				sy = j;
			}
		}
	dfs(sx,sy);
	printf("%d\n",res);
}
/*
4 5
#**@#
**###
#**#*
#*#*#
*/