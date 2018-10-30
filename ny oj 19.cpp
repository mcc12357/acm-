#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int n,m;
int res[15];
int used[15];
void dfs(int t)
{
	int i,j;
	if(t==n)
	{
		for(i=0;i<n;i++) printf("%d",res[i]);
		printf("\n");
		return ;
	}
	for(i=1;i<=m;i++) 
	{
		if(used[i]) continue;
		if(!used[i])
		{
			res[t] = i;
			used[i] = 1;
		}
		dfs(t+1);
		used[i] = 0;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		memset(res,0,sizeof(res));
		memset(used,0,sizeof(used));
		dfs(0);

	}
}