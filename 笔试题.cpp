/*输入m,n，使得m*n矩阵满足和谐矩阵
(和谐矩阵由0,1组成，任意一个数与周围上下左右的数和为偶数且不全为0)*/
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int m,n;
int a[100][100];
bool isres;
bool judge()
{
	int i,j;
	bool res = true;
	int sum = 0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			sum += a[i][j];
			int tmp = 0;
			if(i==0)
			{
				if(j==0)
				{
					tmp = a[i][j] + a[i][j+1] + a[i+1][j];
				}
				else if(j==n-1)
				{
					tmp = a[i][j] + a[i][j-1] + a[i+1][j];
				}
				else
				{
					tmp = a[i][j] + a[i][j-1] + a[i][j+1] + a[i+1][j];
				}
			}
			else if(i==m-1)
			{
				if(j==0)
				{
					tmp = a[i][j] + a[i-1][j] + a[i][j+1];
				}
				else if(j==n-1)
				{
					tmp = a[i][j] + a[i-1][j] + a[i][j-1];
				}
				else
				{
					tmp = a[i][j] + a[i-1][j] + a[i][j-1] + a[i][j+1];
				}
			}
			else
			{
				if(j==0)
				{
					tmp = a[i][j] + a[i-1][j] + a[i+1][j] + a[i][j+1];
				}
				else if(j==n-1)
				{
					tmp = a[i][j] + a[i-1][j] + a[i+1][j] + a[i][j-1];
				}
				else 
				{
					tmp = a[i][j] + a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1];
				}
			}
			if(tmp % 2) res = false;
			if(!res) return false;
		}
	}
	if(res && sum) 
	{
		isres = true;
		return true;
	}
	return false;
}
void dfs(int x,int y,int k)
{
	a[x][y] = k;
	if(x<m-1)
	{
		if(y==n-1)
		{
			dfs(x+1,0,0);
			dfs(x+1,0,1);
		}
		else 
		{
			dfs(x,y+1,0);
			dfs(x,y+1,1);
		}
	}
	if(x==m-1)
	{
		if(y==n-1)
		{
			if(judge()) 
			{
				int i,j;
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						printf("%d",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			return ;
		}
		else
		{
			dfs(x,y+1,0);
			dfs(x,y+1,1);
		}
	}
	return ;
}
int main()
{
	while(~scanf("%d %d",&m,&n))
	{
		isres = false;
		memset(a,0,sizeof(a));
		dfs(0,0,0);
		dfs(0,0,1);
		if(!isres) printf("no result!\n");
	}
}