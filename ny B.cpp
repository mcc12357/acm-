#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
char a[505][505];
int b[8] = {-1,-1,-1,0,0,1,1,1},c[8] = {-1,0,1,-1,1,-1,0,1};
int sum = 0;
int res[100000];
int m,n;
int dfs(int x,int y)
{
	int i,j,temp;
	if(a[x][y]=='1') temp = 1;
	else temp = 0;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			int x1 = x + b[i],y1 = y + c[i];
			if(a[x1][y1]=='1' && x1>0 && x1<m && y1>0 && y1<n)
			{
				temp++;
				a[x1][y1] = '0';
				temp += dfs(x1,y1);
			}
		}
		return temp;
}
int main()
{
	int t;
	scanf("%d %d %d",&m,&n,&t);
	getchar();
	int i=0,j=0,k=0;
	char tt;
	memset(res,-1,sizeof(res));
	while(i<m)
	{
		j = 0;
		while(j<n)
		{
			scanf("%c",&tt);
			if(tt==' ') continue;
			a[i][j] = tt;
			//printf("%c",a[i][j]);
			j++;
		}
		getchar();
		i++;
	}
	/*for(i=0;i<m;i++) 
	{
		for(j=0;j<n;j++) printf("%c",a[i][j]);
		printf("\n");
	}*/
	for(i=1;i<m-1;i++)
		for(j=1;j<n-1;j++)
		{
			if(a[i][j]=='1') 
			{
				sum++;
				res[k++] = dfs(i,j);
			}
		}
	printf("%d ",sum);
	int max = 0;
	for(i=0;i<sum;i++) if(max<res[i]) max = res[i];
	max--;
	printf("%d\n",t*max);
}