#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int map[9][9];
int flag[9][9];
int stand[9] = {1,2,4,8,16,32,64,128,256};
int end;
int judge(int x,int y,int k)
{
	int i,j;
	for(i=0;i<9;i++) 
	{
		if(i==y) continue;
		if( ( ( 1<<(map[x][i]-1) ) & k ) ) return 0;
	}
	for(i=0;i<9;i++) 
	{
		if(i==x) continue;
		if( ( ( 1<<(map[i][y]-1) ) & k ) ) return 0;
	}
	int tx,ty;
	if(x%3==0)
	{
		if(y%3==0)
		{
			for(i=0;i<3;i++)
				for(j=0;j<3;j++) 
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
		else if(y%3==1)
		{
			for(i=0;i<3;i++)
				for(j=-1;j<=1;j++)
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
		else
		{
			for(i=0;i<3;i++)
				for(j=-2;j<=0;j++)
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
	}
	if(x%3==1)
	{
		if(y%3==0)
		{
			for(i=-1;i<=1;i++)
				for(j=0;j<3;j++) 
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
		else if(y%3==1)
		{
			for(i=-1;i<=1;i++)
				for(j=-1;j<=1;j++)
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
		else
		{
			for(i=-1;i<=1;i++)
				for(j=-2;j<=0;j++)
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
	}
	if(x%3==2)
	{
		if(y%3==0)
		{
			for(i=-2;i<=0;i++)
				for(j=0;j<3;j++) 
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
		else if(y%3==1)
		{
			for(i=-2;i<=0;i++)
				for(j=-1;j<=1;j++)
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
		else
		{
			for(i=-2;i<=0;i++)
				for(j=-2;j<=0;j++)
				{
					tx = x + i;
					ty = y + j;
					if(tx==x && ty==y) continue;
					if( ( ( 1<<(map[tx][ty]-1) ) & k ) ) return 0;
				}
		}
	}
	return 1;
}


void dfs(int x,int y)
{
	int i,j;
	if(x==8 && y==8 && map[x][y])
	{
		end = 1;
		return ;
	}
	if(x==8 && y==8 && !map[x][y])
	{
		for(i=0;i<9;i++) 
			if(judge(x,y,stand[i]))
			{
				map[x][y] = i + 1;
				end = 1;
				return ;
			}
	}
	if(end) return;
	if(y!=8)
	{
		if(map[x][y]) 
		{
			dfs(x,y+1);
			if(end) return;
		}
		else
		{
			for(i=0;i<9;i++)
			{
				if(judge(x,y,stand[i]))
				{
					map[x][y] = i + 1;
					dfs(x,y+1);
					if(end) return ;
					map[x][y] = 0;
				}
			}
		}
	}
	else
	{
		if(map[x][y]) 
		{
			dfs(x+1,0);
			if(end) return ;
		}
		else
		{
			for(i=0;i<9;i++)
			{
				if(judge(x,y,stand[i]))
				{
					map[x][y] = i + 1;
					dfs(x+1,0);
					if(end) return ;
					map[x][y] = 0;
				}
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		char c;
		end = 0;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++) 
			{
				cin>>c;
				map[i][j] = c - '0';
			}
		}
		memset(flag,0,sizeof(flag));
		dfs(0,0);
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%d",map[i][j]);
			}
			printf("\n");
		}
	}
}