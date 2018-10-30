#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
struct point 
{
	int x,y;
};
int m,n;
char map[25][25];
int sx,sy,gx,gy;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int key[5];
int visited[25][25];
bool bfs(int mx,int my)
{
	int i;
	if(mx==gx && my==gy) return true;
	visited[mx][my] = 1;
	point tm;
	tm.x = mx;
	tm.y = my;
	queue<point> que;
	que.push(tm);
	while(!que.empty())
	{
		point k = que.front();
		que.pop();
		//visited[k.x][k.y] = 1;
		if(map[k.x][k.y]=='G') return true;
		if(map[k.x][k.y]>='A' && map[k.x][k.y]<='E')
		{
			if(key[map[k.x][k.y]-'A']==0)
			{
				map[k.x][k.y] = '.';
				//que.push(k);
				//visited[k.x][k.y] = 1;
			}
			else 
			{
				if(que.empty())
				{
					return false;
				}
				else
				{
					que.push(k);
					continue;
				}
			}
		}
		for(i=0;i<4;i++)
		{
			point t;
			t.x = k.x + dx[i];
			t.y = k.y + dy[i];
			//if(t.x>=0 && t.x<m && t.y>=0 && t.y<n && map[t.x][t.y]=='G') return true;
			if(t.x>=0 && t.x<m && t.y>=0 && t.y<n && map[t.x][t.y]>='a' && map[t.x][t.y]<='e' && !visited[t.x][t.y])
			{
				key[map[t.x][t.y]-'a']--;
				map[t.x][t.y] = '.';
				que.push(t);
				visited[t.x][t.y] = 1;
			}
			if(t.x>=0 && t.x<m && t.y>=0 && t.y<n && !visited[t.x][t.y] && map[t.x][t.y]!='X')
			{
				que.push(t);
				visited[t.x][t.y] = 1;	
				//printf("%d\n",visited[1][1]);
			}
		
		}
	}
	return false;
}
int main()
{
	while(~scanf("%d %d",&m,&n) && (m||n))
	{
		int i,j;
		memset(key,0,sizeof(key));
		memset(visited,0,sizeof(visited));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				cin >> map[i][j];
				if(map[i][j]=='S')
				{
					sx = i;
					sy = j;
				}
				if(map[i][j]=='G')
				{
					gx = i;
					gy = j;
				}
				if(map[i][j]>='a' && map[i][j]<='e') key[map[i][j]-'a']++;
			}
			if(bfs(sx,sy)) printf("YES\n");
			else printf("NO\n");
	}
	return 0;
}
