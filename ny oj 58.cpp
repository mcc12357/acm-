#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
struct point
{
	int x,y;
};
int map[9][9] = 
{
1,1,1,1,1,1,1,1,1,
1,0,0,1,0,0,1,0,1,
1,0,0,1,1,0,0,0,1,
1,0,1,0,1,1,0,1,1,
1,0,0,0,0,1,0,0,1,
1,1,0,1,0,1,0,0,1,
1,1,0,1,0,1,0,0,1,
1,1,0,1,0,0,0,0,1,
1,1,1,1,1,1,1,1,1
};
int mark[9][9];
int sx,sy,gx,gy;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int res[9][9];
void bfs()
{
	int i;
	queue<point> que;
	if(sx==gx && sy==gy) return ;
	point tm;
	tm.x = sx;
	tm.y = sy;
	que.push(tm);
	while(!que.empty())
	{
		tm = que.front();
		que.pop();
		mark[tm.x][tm.y] = 1;
		if(tm.x==gx && tm.y==gy) return;
		//int flag = 0;
		for(i=0;i<4;i++)
		{
			//res++;
			point k;
			k.x = tm.x + dx[i];
			k.y = tm.y + dy[i];
			if(k.x>=0 && k.x<9 && k.y>=0 && k.y<9 && !map[k.x][k.y] && !mark[k.x][k.y])
			{
				que.push(k);
				//flag = 1;
				res[k.x][k.y] = res[tm.x][tm.y] + 1;
			}
			//if(flag) res--;
		}
		
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(mark,0,sizeof(mark));
		scanf("%d %d %d %d",&sx,&sy,&gx,&gy);
		res[sx][sy] = 0;
		bfs();
		printf("%d\n",res[gx][gy]);
	}
	return 0;
}