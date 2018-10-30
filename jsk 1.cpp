#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
struct Line
{
	int x1,y1,x2,y2,x3,y3;
}line[16];
bool used[10][10];
void init()
{
	Line tm;
	tm.x1 = -3;
	tm.y1 = 3;
	tm.x2 = -3;
	tm.y2 = 0;
	tm.x3 = -3;
	tm.y3 = -3;
	line[0] = tm;
	tm.x2 = 0;
	tm.y2 = 3;
	tm.x3 = 3;
	tm.y3 = 3;
	line[1] = tm;
	tm.x1 = 3;
	tm.y1 = 3;
	tm.x2 = 3;
	tm.y2 = 0;
	tm.x3 = 3;
	tm.y3 = -3;
	line[2] = tm;
	tm.x1 = -3;
	tm.y1 = -3;
	tm.x2 = 0;
	tm.y2 = -3;
	tm.x3 = 3;
	tm.y3 = -3;
	line[3] = tm;
	tm.x1 = -2;
	tm.y1 = 2;
	tm.x2 = 0;
	tm.y2 = 2;
	tm.x3 = 2;
	tm.y3 = 2;
	line[4] = tm;
	tm.x2 = -2;
	tm.y2 = 0;
	tm.x3 = -2;
	tm.y3 = -2;
	line[5] = tm;
	tm.x1 = -2;
	tm.y1 = -2;
	tm.x2 = 0;
	tm.y2 = -2;
	tm.x3 = 2;
	tm.y3 = -2;
	line[6] = tm;
	tm.x1 = 2;
	tm.y1 = 2;
	tm.x2 = 2;
	tm.y2 = 0;
	tm.x3 = 2;
	tm.y3 = -2;
	line[7] = tm;
	tm.x1 = -1;
	tm.y1 = 1;
	tm.x2 = 0;
	tm.y2 = 1;
	tm.x3 = 1;
	tm.y3 = 1;
	line[8] = tm;
	tm.x2 = -1;
	tm.y2 = 0;
	tm.x3 = -1;
	tm.y3 = -1;
	line[9] = tm;
	tm.x1 = -1;
	tm.y1 = -1;
	tm.x2 = 0;
	tm.y2 = -1;
	tm.x3 = 1;
	tm.y3 = -1;
	line[10] = tm;
	tm.x1 = 1;
	tm.y1 = 1;
	tm.x2 = 1;
	tm.y2 = 0;
	tm.x3 = 1;
	tm.y3 = -1;
	line[11] = tm;
	tm.x1 = -3;
	tm.y1 = 0;
	tm.x2 = -2;
	tm.y2 = 0;
	tm.x3 = -1;
	tm.y3 = 0;
	line[12] = tm;
	tm.x1 = tm.x2 = tm.x3 = 0;
	tm.y1 = 1;
	tm.y2 = 2;
	tm.y3 = 3;
	line[13] = tm;
	tm.y1 = -1;
	tm.y2 = -2;
	tm.y3 = -3;
	line[14] = tm;
	tm.y1 = tm.y2 = tm.y3 = 0;
	tm.x1 = 1;
	tm.x2 = 2;
	tm.x3 = 3;
	line[15] = tm;

}
int main()
{
	memset(used,0,sizeof(used));
	init();
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a += 3;
		b += 3;
		used[a][b] = true;
	}
	for(i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
	}
	int ans = 0;
	for(i=0;i<16;i++)
	{
		int p1,q1,p2,q2,p3,q3;
		p1 = line[i].x1 + 3;
		q1 = line[i].y1 + 3;
		p2 = line[i].x2 + 3;
		q2 = line[i].y2 + 3;
		p3 = line[i].x3 + 3;
		q3 = line[i].y3 + 3;
		if(used[p1][q1] && used[p2][q2] && used[p3][q3]) ans++;
	}
	printf("%d\n",ans);
}