#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
int dx[] = {0,-1,0,1,0};
int dy[] = {1,0,-1,0,0};
int tile[5][6];
int flip[5][6];
//int opt[5][6];
int get(int x,int y)
{
	int c = tile[x][y];
	int d;
	for(d=0;d<5;d++)
	{
		int x2 = x + dx[d];
		int y2 = y + dy[d];
		if(x2>=0 && x2<5 && y2>=0 && y2<6)
		{
			c += flip[x2][y2];
		}
	}
	return c % 2;
}
bool cal()
{
	int i,j;
	for(i=1;i<5;i++)
		for(j=0;j<6;j++)
		{
			if(get(i-1,j)!=0) flip[i][j] = 1;
		}
	for(j=0;j<6;j++)
	{
		if(get(4,j)!=0) return false;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	int u,i,j;
	for(u=1;u<=t;u++)
	{
		for(i=0;i<5;i++)
			for(j=0;j<6;j++) cin>>tile[i][j];
		printf("PUZZLE #%d\n",u);
		//int res = -1;
		for(i=0;i< 1<<6;i++)
		{
			memset(flip,0,sizeof(flip));
			for(j=0;j<6;j++)
			{
				flip[0][6-j-1] = i>>j&1;
			}
			if(cal()) break;
		}
		for(i=0;i<5;i++)
			for(j=0;j<6;j++)
			{
				if(j<5) printf("%d ",flip[i][j]);
				if(j==5) printf("%d\n",flip[i][j]);
			}
	}
	return 0;
}