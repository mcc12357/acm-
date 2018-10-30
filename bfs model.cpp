#include<iostream>
using  namespace std;
#include<queue>
const int INF = 100000000;
int m,n;
int sx,sy,gx,gy;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int d[101][101];
char maze[101][101];
struct P
{
	int first,second;
};
//typedef pair<int,int> P;
int bfs()
{
	int i,j;
	queue<P> que;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) d[i][j] = INF;
	P temp;
	temp.first = sx;
	temp.second = sy;
	que.push(temp);
	d[sx][sy] = 0;
	while(que.size())
	{
		P p = que.front();
		que.pop();
		if(p.first == gx && p.second == gy) break;
		for(i=0;i<4;i++)
		{
			int nx = p.first + dx[i],ny = p.second + dy[i];
			if(0<=nx && nx<m && 0<= ny && ny < n && maze[nx][ny] != '#' && d[nx][ny]==INF)
			{
				temp.first = nx;
				temp.second = ny;
				que.push(temp);
				d[nx][ny] = d[p.first][p.second] + 1; 
			}
		}
	}
	return d[gx][gy];
}
int main()
{
	cin >> m >> n;
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) cin >> maze[i][j];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) 
		{
			if(maze[i][j]=='s') {sx = i;sy = j;}
			if(maze[i][j]=='g') {gx = i;gy = j;}
		}
	int res = bfs();
	cout << res << endl;
}