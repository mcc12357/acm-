#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 1010
bool used[maxn];
int m,n;
int num = 0;
void dfs(int x,int y,int a[])
{
	if(num>=m) return ;
	a[x] = y;
	if(x==n)
	{
		num++;
		return ;
	}
	int i;
	for(i=1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i] = true;
			dfs(x+1,i,a);
			used[i] = false;
		}
	}
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		num = 0;
		memset(used,0,sizeof(used));
		int a[maxn];
		dfs(0,0,a);
		int i;
		for(i=1;i<n;i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
}
