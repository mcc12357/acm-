//³¬ÄÚ´æ
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
char map[305][305];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
struct point 
{
	int x,y;
	char pass;
	int step;
	point(int x1,int y1,char pass1,int step1):x(x1),y(y1),pass(pass1),step(step1){}
	point(){}
};
int sx,sy;
int m,n;
int res;
bool flag;
queue<point> que;
void bfs(int sx,int sy)
{
	//queue<point> que;
	while(que.size()) que.pop();
	point tm;
	int i;
	/*tm.x = sx;
	tm.y = sy;
	tm.pass = 'S';
	tm.step = 0;
	que.push(tm);*/
	que.push(point(sx,sy,'S',0));
	while(que.size())
	{
		point tn = que.front();
		que.pop();
		if(map[tn.x][tn.y]=='T')
		{
			flag = true;
			res = tn.step;
			return;
		}
		if(tn.pass=='B')
		{
			/*point tp = tn;
			tp.pass = 'E';
			tp.step++;
			que.push(tp);*/
			que.push(point(tn.x,tn.y,'E',tn.step+1));
			continue;
		}
		for(i=0;i<4;i++)
		{
			point tp;
			tp.x = tn.x + dx[i];
			tp.y = tn.y + dy[i];
			if(tp.x>=0 && tp.x<m && tp.y>=0 && tp.y<n && (map[tp.x][tp.y]=='B' || map[tp.x][tp.y]=='E' || map[tp.x][tp.y]=='T'))
			{
				tp.pass = map[tp.x][tp.y];
				tp.step = tn.step + 1;
				que.push(tp);
			}
		}
	}
}
int main()
{
	while(~scanf("%d %d",&m,&n) && (m||n))
	{
		int i,j;
		flag = false;
		//memset(visited,0,sizeof(visited));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++) 
			{
				cin>>map[i][j];
				if(map[i][j]=='Y')
				{
					sx = i;
					sy = j;
				}
				if(map[i][j]=='R') map[i][j] = 'S';
			}
		bfs(sx,sy);
		if(flag) printf("%d\n",res);
		else printf("-1\n");

	}
}