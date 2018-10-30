#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
char map[50][50];
bool can[50];
bool iskey[50][50];
bool vis[50][50];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int m,n,k;
const int inf = 10000;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
struct Point
{
	int x,y,pace;
	bool flag[15];
};
struct Tun
{
	int x,y;
}T[50][50];
Point s;
queue<Point> q;
int main()
{
	int t;
	scanf("%d",&t);
	int count = 1;
	while(t--)
	{
		scanf("%d %d %d",&m,&n,&k);
		int i,j,r;
		while(!q.empty()) q.pop();
		memset(can,0,sizeof(can));
		memset(iskey,0,sizeof(iskey));
		memset(vis,0,sizeof(vis));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='X')
				{
					s.x = i;
					s.y = j;
					s.pace = 0;
				}
			}
		bool flag;
		for(i=0;i<k;i++)
		{
			flag = false;
			Tun t1,t2;
			for(j=0;j<m;j++)
			{
				for(r=0;r<n;r++)
				{
					if(flag && map[j][r]=='A'+i)
					{
						t2.x = j;
						t2.y = r;
						T[t1.x][t1.y].x = t2.x;
						T[t1.x][t1.y].y = t2.y;
						T[t2.x][t2.y].x = t1.x;
						T[t2.x][t2.y].y = t1.y;
					}
					if(!flag && map[j][r]=='A'+i)
					{
						flag = true;
						t1.x = j;
						t1.y = r;
					}
				}
			}
		}
		int tm;
		scanf("%d",&tm);
		for(i=0;i<k;i++) s.flag[i] = false;
		for(i=1;i<=tm;i++)
		{
			char a;
			cin>>a;
			can[a-'A'] = true;
			s.flag[a-'A'] = true;
		}
		for(i=0;i<k;i++)
		{
			char a;
			scanf("%d",&tm);
			for(j=1;j<=tm;j++)
			{
				cin>>a;
				iskey[a-'A'][i] = true;
			}
		}
		q.push(s);
		int ans = inf;
		while(!q.empty())
		{
			Point cur;
			cur = q.front();
			q.pop();
			vis[cur.x][cur.y] = true;
			if(map[cur.x][cur.y]=='Y')
			{
				ans = cur.pace;
				break;
			}
			else if(map[cur.x][cur.y]>='A' && map[cur.x][cur.y]<'A'+k)
			{
				int w = map[cur.x][cur.y]-'A';
				for(i=0;i<k;i++)
				{
					if(!cur.flag[w] && iskey[i][w])
					{
						//tflag = true;
						cur.flag[w] = true;
					}
				}
				if(cur.flag[w])
				{
					Point tm;
					tm = cur;
					tm.x = T[cur.x][cur.y].x;
					tm.y = T[cur.x][cur.y].y;
					tm.pace = cur.pace + 1;
					if(!vis[tm.x][tm.y]) q.push(tm);
					memset(vis,0,sizeof(vis));
				}
				bool tflag = false;
				
				//if(tflag) memset(vis,0,sizeof(vis));
			}
			for(i=0;i<4;i++)
			{
				int tx = cur.x + dx[i];
				int ty = cur.y + dy[i];
				if(tx>=0 && tx<m && ty>=0 && ty<n && !vis[tx][ty] && (map[tx][ty]=='.' || map[tx][ty]=='X' || map[tx][ty]=='Y' || map[tx][ty]>='A' && map[tx][ty]<'A'+k && cur.flag[map[tx][ty]-'A']))
				{
					Point tm;
					tm = cur;
					tm.x = tx;
					tm.y = ty;
					tm.pace = cur.pace + 1;
					q.push(tm);
				}
			}
		}
		printf("Case #%d: ",count);
		count++;
		if(ans==inf) printf("Unreachable\n");
		else printf("%d\n",ans);
	}
}