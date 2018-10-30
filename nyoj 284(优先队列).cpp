#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
int m,n;
int sx,sy;
int res;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
char map[305][305];
int visited[305][305];
struct node
{
	int x,y,step;
	friend bool operator < (const node &s1,const node &s2)//标准函数库默认<确定元素优先级关系
	{
		return s1.step > s2.step;
	}
};
const int inf = 1e7;
void bfs(int sx,int sy)
{
	priority_queue<node> q;
	node tm;
	tm.step = 0;
	tm.x = sx;
	tm.y = sy;
	q.push(tm);
	while(!q.empty())
	{
		tm = q.top();
		q.pop();
		if(map[tm.x][tm.y]=='T') 
		{
			res = tm.step;
			return ;
		}
		int i;
		for(i=0;i<4;i++)
		{
			int tx = tm.x + dx[i];
			int ty = tm.y + dy[i];
			if(tx>=0 && tx<m && ty>=0 && ty<n && map[tx][ty]!='S' && map[tx][ty]!='R' && !visited[tx][ty])
			{
				node tp;
				tp.x = tx;
				tp.y = ty;
				if(map[tx][ty]=='B') tp.step = tm.step + 2;
				else tp.step = tm.step + 1;
				q.push(tp);
				visited[tx][ty] = 1;
			}
		}
	}
}
int main()
{
	while(~scanf("%d %d",&m,&n) && (m||n))
	{
		int i,j;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++) 
			{
				cin>>map[i][j];
				if(map[i][j]=='Y')
				{
					sx = i;
					sy = j;
					map[i][j] = 'S';
				}
			}
		memset(visited,0,sizeof(visited));
		res = inf;
		bfs(sx,sy);
		if(res==inf) printf("-1\n");
		else printf("%d\n",res);
	}
	return 0;
}