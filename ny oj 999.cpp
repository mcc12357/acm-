//ดํมห
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
char map[105][105];
//int num[105][105];
int sees[105][105];
int seeb[105][105];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int visited[105][105];
int m,n,t;
const int inf = 1e8;
int sx,sy,gx1,gy1,gx2,gy2,res,flag1,flag2;
void dfs(int x,int y,int tt)
{
	if(tt>res || tt>t) return;
	//if(tt>num[x][y]) return;
	//if(tt<num[x][y]) num[x][y] = tt;
	if(sees[x][y]) flag1 = 1;
	if(seeb[x][y]) flag2 = 1;
	if(flag1 && flag2)
	{
		if(tt<res) res = tt;
		return ;
	}
	visited[x][y] = 1;
	int i;
	for(i=0;i<4;i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx>=0 && tx<m && ty>=0 && ty<n && !visited[tx][ty] && map[tx][ty]=='.')
		{
			int r1 = 0,r2 = 0;
			visited[tx][ty] = 1;
			if(sees[tx][ty] && !flag1) {flag1 = 1;r1 = 1;}
			if(seeb[tx][ty] && !flag2) {flag2 = 1;r2 = 1;}
			dfs(tx,ty,tt+1);
			visited[tx][ty] = 0;
			if(r1) flag1 = 0;
			if(r2) flag2 = 0;
		}
	}
	visited[x][y] = 0;
	//flag1 = 0;
	//flag2 = 0;
}
int main()
{
	int k = 1;
	while(~scanf("%d %d %d",&m,&n,&t))
	{
		
		int i,j;
		flag1 = 0;
		flag2 = 0;
		res = inf;
		memset(sees,0,sizeof(sees));
		memset(seeb,0,sizeof(seeb));
		memset(visited,0,sizeof(visited));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='S')
				{
					sx = i;
					sy = j;
					//map[i][j] = 'X';
				}
				if(map[i][j]=='D')
				{
					gx1 = i;
					gy1 = j;
					//map[i][j] = '.';
				}
				if(map[i][j]=='E')
				{
					gx2 = i;
					gy2 = j;
					//map[i][j] = '.';
				}
			}
		printf("Case %d:\n",k);
		k++;
		sees[gx1][gy1] = 1;
		for(i=gy1+1;i<n && (map[gx1][i]=='.' || map[gx1][i]=='S');i++) sees[gx1][i] = 1;
		for(i=gy1-1;i>=0 && (map[gx1][i]=='.' || map[gx1][i]=='S');i--) sees[gx1][i] = 1;
		for(i=gx1-1;i>=0 && (map[i][gy1]=='.' || map[i][gy1]=='S');i--) sees[i][gy1] = 1;
		for(i=gx1+1;i<m && (map[i][gy1]=='.' || map[i][gy1]=='S');i++) sees[i][gy1] = 1;
		seeb[gx2][gy2] = 1;
		for(i=gy2+1;i<n && (map[gx2][i]=='.' || map[gx2][i]=='S');i++) seeb[gx2][i] = 1;
		for(i=gy2-1;i>=0 && (map[gx2][i]=='.' || map[gx2][i]=='S');i--) seeb[gx2][i] = 1;
		for(i=gx2-1;i>=0 && (map[i][gy2]=='.' || map[i][gy2]=='S');i--) seeb[i][gy2] = 1;
		for(i=gx2+1;i<m && (map[i][gy2]=='.' || map[i][gy2]=='S');i++) seeb[i][gy2] = 1;
		//map[sx][sy] = 'X';
		//map[gx1][gy1] = '.';
		//map[gx2][gy2] = '.';
		/*for(i=0;i<m;i++)
			for(j=0;j<n;j++) num[i][j] = inf;*/
		dfs(sx,sy,0);
		if(res==inf) printf("-1\n");
		else printf("%d\n",res);
	}
	return 0;
}