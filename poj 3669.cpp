#include<iostream>
using namespace std;
#include<stdio.h>
#include<queue>
#include<string.h>
int dx[] = {-1,0,1,0,0};
int dy[] = {0,-1,0,1,0};
int min(int x,int y)
{
	if(x<y) return x;
	else return  y;
}
struct node
{
	int x,y,time;
};
int map[405][405];
int bfs()
{
	int i;
	if(map[0][0]==-1) return 0;
	if(map[0][0]==0) return -1;
	node tmp,now;
	tmp.x = tmp.y = tmp.time = 0;
	queue<node> que;
	que.push(tmp);
	while(!que.empty())
	{
		now = que.front();
		que.pop();
		for(i=0;i<5;i++)
		{
			tmp.x = now.x + dx[i];
			tmp.y = now.y + dy[i];
			tmp.time = now.time + 1;
			if(tmp.x<0 || tmp.x>=405 || tmp.y<0 || tmp.y>=405) continue;
			if(map[tmp.x][tmp.y]==-1) return tmp.time;
			if(tmp.time>=map[tmp.x][tmp.y]) continue;
			map[tmp.x][tmp.y] = tmp.time;//走过的路当成已被毁坏的路，就不再走回头路
			que.push(tmp);
		}
	}
	return -1;
}
int main()
{
	int m,a,b,tt,i;
	while(~scanf("%d",&m))
	{
		memset(map,-1,sizeof(map));
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&tt);
			for(i=0;i<5;i++)
			{
				int tx = a + dx[i],ty = b + dy[i];
				if( tx<0||ty<0||tx>300||ty>300 ) continue;
				if(map[tx][ty]==-1) map[tx][ty] = tt;
				else map[tx][ty] = min(map[tx][ty],tt);
			}
		}
		printf("%d\n",bfs());
	}
	return 0;
}