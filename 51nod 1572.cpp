#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1010
int m,n,k;
char map[maxn][maxn];
int l[maxn][maxn],r[maxn][maxn],u[maxn][maxn],d[maxn][maxn];
bool can[30];
int x[30],y[30];
char val[30];
char dir[100010];
int pace[100010];
int main()
{
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=0;i<m;i++)
	{
		scanf("%s",map[i]);
	}
	scanf("%d",&k);
	for(i=0;i<k;i++) 
	{
		getchar();
		scanf("%c %d",&dir[i],&pace[i]);
	}
	int p = 0;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(map[i][j]>='A' && map[i][j]<='Z')
			{
				x[p] = i;
				y[p] = j;
				val[p] = map[i][j];
				p++;
			}
		}
	//初始化向左走最大步数
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==0) l[i][j] = 0;
			else
			{
				if(map[i][j-1]!='#') l[i][j] = l[i][j-1] + 1;
			}
		}
	}
	//初始化向右走最大步数
	for(i=0;i<m;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			if(j==n-1) r[i][j] = 0;
			else
			{
				if(map[i][j+1]!='#') r[i][j] = r[i][j+1] + 1;
			}
		}
	}
	//初始化向上走的最大步数
	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			if(i==0) u[i][j] = 0;
			else
			{
				if(map[i-1][j]!='#') u[i][j] = u[i-1][j] + 1;
			}
		}
	}
	//初始化向下走的最大步数
	for(j=0;j<n;j++)
	{
		for(i=m-1;i>=0;i--)
		{
			if(i==m-1) d[i][j] = 0;
			else
			{
				if(map[i+1][j]!='#') d[i][j] = d[i+1][j] + 1; 
			}
		}
	}
	for(i=0;i<p;i++)
	{
		bool flag = true;
		int sx = x[i],sy = y[i];
		for(j=0;j<k;j++)
		{
			if(dir[j]=='N')
			{
				if(u[sx][sy]<pace[j])
				{
					flag = false;
					break;
				}
				else sx -= pace[j];
			}
			if(dir[j]=='S')
			{
				if(d[sx][sy]<pace[j])
				{
					flag = false;
					break;
				}
				else sx += pace[j];
			}
			if(dir[j]=='W')
			{
				if(l[sx][sy]<pace[j])
				{
					flag = false;
					break;
				}
				else sy -= pace[j];
			}
			if(dir[j]=='E')
			{
				if(r[sx][sy]<pace[j])
				{
					flag = false;
					break;
				}
				else sy += pace[j];
			}
		}
		if(flag) can[val[i]-'A'] = true;
	}
	bool flag = false;
	for(i=0;i<=25;i++) 
	{
		if(can[i]) 
		{
			printf("%c",i+'A');
			flag = true;
		}
	}
	if(flag) printf("\n");
	else printf("no solution\n");
}
/*
6 10
##########
###..#####
#.#..##.##
#..#.#...#
#######A.#
##########
4
N 2
S 1
E 1
W 2
*/
