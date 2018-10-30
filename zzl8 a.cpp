#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 10
char map[maxn][maxn];
int n,k;
struct Point
{
	int x,y;
}point[80];
int ans;
int p = 0;
bool usedx[10];
bool usedy[10];
void dfs(int num,int s)
{
	if(num==k)
	{
		ans++;
		return ;
	}
	int i;
	for(i=s;i<p;i++)
	{
		int tx = point[i].x,ty = point[i].y;
		if(!usedx[tx] && !usedy[ty])
		{
			usedx[tx] = true;
			usedy[ty] = true;
			dfs(num+1,i+1);
			usedx[tx] = false;
			usedy[ty] = false;
		}
	}
}
int main()
{
	while(~scanf("%d %d",&n,&k))
	{
		if(n==-1 && k==-1) break;
		p = 0;
		ans = 0;
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) 
			{
				cin>>map[i][j];
				if(map[i][j]=='#')
				{
					point[p].x = i;
					point[p].y = j;
					p++;
				}
			}
		memset(usedx,0,sizeof(usedx));
		memset(usedy,0,sizeof(usedy));
		dfs(0,0);
		printf("%d\n",ans);
	}
}