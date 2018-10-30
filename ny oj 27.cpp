#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int map[105][105];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int m,n;
void dfs(int x,int y)
{
	int i;
	map[x][y] = 0;
	for(i=0;i<4;i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx>=0 && tx<m && ty>=0 && ty<n && map[tx][ty]==1) dfs(tx,ty);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		//int m,n;
		scanf("%d %d",&m,&n);
		int i,j;
		for(i=0;i<m;i++) for(j=0;j<n;j++) scanf("%d",&map[i][j]);
		int res = 0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(map[i][j]==1)
				{
					dfs(i,j);
					res++;
				}
			}
			printf("%d\n",res);
	}
	return 0;
}