#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 60
int m,n;
char map[maxn][maxn];
bool vis[maxn][maxn],cvis[maxn][maxn];
bool flag = false;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void dfs(int x,int y,int dir)
{
	if(flag) return ;
	vis[x][y] = true;
	if(cvis[x][y]==true)
	{
		flag = true;
		return ;
	}
	cvis[x][y] = true;
	int k;
	if(dir==-1)
	{
		for(k=0;k<4;k++)
		{
			int sx = x + dx[k],sy = y + dy[k];
			if(sx>=0 && sx<m && sy>=0 && sy<n && map[sx][sy]==map[x][y])
			{
				dfs(sx,sy,k);
			}
		}
	}
	else
	{
		for(k=0;k<4;k++)
		{
			if((dir+k)%4==1) continue;
			int sx = x + dx[k],sy = y + dy[k];
			if(sx>=0 && sx<m && sy>=0 && sy<n && map[sx][sy]==map[x][y])
			{
				dfs(sx,sy,k);
			}
		}
	}
	
}
int main()
{
	cin>>m>>n;
	int i,j,k;
	for(i=0;i<m;i++) 
	{
		for(j=0;j<n;j++) cin>>map[i][j];
	}
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			memset(cvis,0,sizeof(cvis));
			dfs(i,j,-1);
			if(flag) break;
		}
	if(flag) printf("Yes\n");
	else printf("No\n");
}