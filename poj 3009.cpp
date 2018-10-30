#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int m,n,sx,sy,res;
int map[25][25];
//int visited[25][25];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
void dfs(int x,int y,int t)
{
	if(t>res) return ;
	if(map[x][y]==3)
	{
		if(t<res) res = t;
		return ;
	}
	int i;
	for(i=0;i<4;i++)
	{
		int flag = 0;
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx>=0 && tx<m && ty>=0 && ty<n && (map[tx][ty]==0||map[tx][ty]==3))
		{
			while(1)
			{
				if(tx==m || ty==n || tx==-1 || ty==-1) {flag = 1;break;}
				if(map[tx][ty]==1)
				{
					map[tx][ty] = 0;
					break;
				}
				if(map[tx][ty]==3) {dfs(tx,ty,t+1);return ;}
				tx += dx[i];
				ty += dy[i];
			}
			if(flag) continue;
			dfs(tx-dx[i],ty-dy[i],t+1);
			map[tx][ty] = 1;
		}
	}
}
int main()
{
	while(~scanf("%d %d",&n,&m) && (m||n))
	{
		int i,j;
		res = 12;
		//memset(visited,0,sizeof(visited));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++) 
			{
				cin>>map[i][j];
				if(map[i][j]==2)
				{
					sx = i;
					sy = j;
				}
			}
		map[sx][sy] = 0;
		dfs(sx,sy,0);
		if(res>10) printf("-1\n");
		else printf("%d\n",res);

	}
}
