#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#define maxn 35
struct Point 
{
	int x,y,z,step;
}s;
int m,n,c;
queue<Point> q;
char map[maxn][maxn][maxn];
bool used[maxn][maxn][maxn];
char p[maxn];
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {1,-1,0,0,0,0};
int main()
{
	while(~scanf("%d %d %d",&c,&m,&n) && (c || m || n))
	{
		memset(used,0,sizeof(used));
		int i,j,k;
		for(i=0;i<c;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%s",map[i][j]);
				for(k=0;k<n;k++)
				{
					if(map[i][j][k]=='S')
					{
						s.z = i;
						s.x = j;
						s.y = k;
						s.step = 0;
					}
					if(map[i][j][k]=='#')
					{
						used[i][j][k] = true;
					}
				}
			}
			gets(p);
		}
		while(!q.empty()) q.pop();
		q.push(s);
		used[s.z][s.x][s.y] = true;
		bool flag = false;
		int ans = 0;
		while(!q.empty())
		{
			Point cur = q.front();
			q.pop();
			if(map[cur.z][cur.x][cur.y]=='E')
			{
				flag = true;
				ans = cur.step;
				break;
			}
			for(i=0;i<6;i++)
			{
				int tx = cur.x + dx[i];
				int ty = cur.y + dy[i];
				int tz = cur.z + dz[i];
				if(tz>=0 && tz<c && tx>=0 && tx<m && ty>=0 && ty<n && !used[tz][tx][ty] )
				{
					Point in;
					in.x = tx;
					in.y = ty;
					in.z = tz;
					in.step = cur.step + 1;
					q.push(in);
					used[tz][tx][ty] = true;
				}
			}

		}
		if(flag) printf("Escaped in %d minute(s).\n",ans);
		else printf("Trapped!\n");

	}
}