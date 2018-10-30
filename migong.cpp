#include<iostream>
#include<queue>
using namespace std;
const int INF = 100000000;
typedef pair<int,int> P;
char maze[100][100];
int m,n;
int sx,sy,gx,gy;
int d[100][100];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int bfs()
{
	int i,j;
	queue<P> que;
	for(i=0;i<m;i++) for(j=0;j<n;j++) d[i][j] = INF;
	que.push(P(sx,sy));
	d[sx][sy] = 0;
	while(que.size())
	{
		P p = que.front();
		que.pop();
		if(p.first == gx && p.second == gy) break;
		for(i=0;i<4;i++)
		{
			int nx = p.first + dx[i],ny = p.second + dy[i];
			if(nx >=0 && nx < m && ny >= 0 && ny < n && maze[nx][ny]!='#' && d[nx][ny] == INF)
			{
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}

	}
	return d[gx][gy];
}
int main()
{
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++) 
	{
		for(j=0;j<n;j++) cin>>maze[i][j];
	}
	for(i=0;i<m;i++) for(j=0;j<n;j++) 
	{
		if(maze[i][j]=='S') {sx = i;sy = j;}
		if(maze[i][j]=='G') {gx = i;gy = j;}
	}
	int res = bfs();
	printf("%d\n",res);
}