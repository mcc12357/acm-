#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#pragma comment(linker,"/stack:1024000000,1024000000")
#define n 16
char map1[20][20];
int map[20][20];
int used[20];
int hang[20][20],lie[20][20],grid[5][5][20];
int k;
struct Pos
{
	int x,y;
	int size;
	vector<int> g;
}pos[400];
bool cmp(Pos a,Pos b)
{
	return a.size<b.size;
}
/*
bool judge(int val,int x,int y)
{
	int i,j;
	for(i=0;i<n;i++) if(map[x][i]==val) return false;
	for(i=0;i<n;i++) if(map[i][y]==val) return false;
	for(i=x/4*4;i<x/4*4+4;i++)
		for(j=y/4*4;j<y/4*4+4;j++)
		{
			if(map[i][j]==val) return false;
		}
	return true;
}
void f(int x,int y)
{
	int i,j;
	for(i=0;i<n;i++) if(map[x][i]>=0) used[map[x][i]] = 1;
	for(i=0;i<n;i++) if(map[i][y]>=0) used[map[i][y]] = 1;
	for(i=x/4*4;i<x/4*4+4;i++)
		for(j=y/4*4;j<y/4*4+4;j++)
		{
			if(map[i][j]>=0) used[map[i][j]] = 1;
		}
}
*/
bool dfs(int t)
{
	int i,j;
	for(i=t;i<k;i++)
	{	
		bool flag = true;
		for(j=0;j<pos[i].size;j++)
		{
			if(!hang[pos[i].x][pos[i].g[j]] && !lie[pos[i].y][pos[i].g[j]] && !grid[pos[i].x/4][pos[i].y/4][pos[i].g[j]]) flag = false;
			if(!flag) break;
		}
		if(flag) return false;
	}
	if(t==k-1)
	{
		for(i=0;i<pos[t].size;i++)
		{
			int xx = pos[t].x;
			int yy = pos[t].y;
			int val = pos[t].g[i];
			if(!hang[xx][val] && !lie[yy][val] && !grid[xx/4][yy/4][val])
			{
				map[xx][yy] = val;
				return true;
			}
		}
	}
	for(i=0;i<pos[t].size;i++)
	{
		int xx = pos[t].x;
		int yy = pos[t].y;
		int val = pos[t].g[i];
		if(hang[xx][val] || lie[yy][val] || grid[xx/4][yy/4][val]) continue;
		map[xx][yy] = val;
		hang[xx][val]++;
		lie[yy][val]++;
		grid[xx/4][yy/4][val]++;
		if(dfs(t+1)) return true;
		//map[pos[t].x][pos[t].y] = -1;
		hang[xx][val]--;
		lie[yy][val]--;
		grid[xx/4][yy/4][val]--;
	}
	return false;
}
int main()
{
	int i,j,m;
	memset(hang,0,sizeof(hang));
	memset(lie,0,sizeof(lie));
	memset(grid,0,sizeof(grid));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) 
		{
			cin>>map1[i][j];
			if(map1[i][j]!='-') 
			{
				map[i][j] = (map1[i][j] - 'A');
				hang[i][map[i][j]]++;
				lie[j][map[i][j]]++;
				grid[i/4][j/4][map[i][j]]++;
			}
			else map[i][j] = -1;
		}
	for(i=0;i<=260;i++) pos[i].g.clear();
	k = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(map[i][j]<0)
			{
				pos[k].x = i;
				pos[k].y = j;
				//memset(used,0,sizeof(used));
				//f(i,j);
				for(m=0;m<=15;m++)
				{
					//if(!used[m]) pos[k].g.push_back(m);
					if(!hang[i][m] && !lie[j][m] && !grid[i/4][j/4][m]) pos[k].g.push_back(m);  
				}
				pos[k].size = pos[k].g.size();
				k++;
			}
		}
	sort(pos,pos+k,cmp);
	//printf("%d\n",pos[0].size);
	dfs(0);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(j!=n-1) printf("%c",'A'+map[i][j]);
			else printf("%c\n",'A'+map[i][j]);
		}
		
}