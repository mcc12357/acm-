#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
struct point
{
	int x,int y;
	int parent;
	point (int x1,int y1,int parent1):x(x1),y(y1),parent(parent1){}
	point(){}
};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int map[105][105];
int resultx[10005],resulty[10005];
point que[10005];
int qfront = 0,qtail = 0;
int visited[105][105];
int main()
{
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	char c;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) {cin>>c;map[i][j] = c - '0';}
	memset(visited,0,sizeof(visited));
	que[qtail++] = point(0,0,0);
	while(qfront!=qtail)
	{
		point tm = que[qfront];
		if(tm.x==m-1 && tm.y==n-1) break;
		qfront++;
		visited[tm.x][tm.y] = 1;
		for(i=0;i<4;i++)
		{
			int tx = tm.x + dx[i];
			int ty = tm.y + dy[i];
			if(tx>=0 && tx<m && ty>=0 && ty<n && !visited[tx][ty] && map[tx][ty]==0)
			{
				que[qtail++] = point(tx,ty,qfront-1);
			}
		}
	}
	int k = 0;
	while(!(que[que[qfront].parent].x==0 && que[que[qfront].parent].y==0)) 
	{
		resultx[k] = que[que[qfront].parent].x;
		resulty[k] = que[que[qfront].parent].y;
		k++;
		qfront = que[qfront].parent;
	}
	printf("0 0\n");
	for(i=k-1;i>=0;i--) printf("%d %d\n",resultx[i],resulty[i]);
	printf("%d %d\n",m-1,n-1);
}