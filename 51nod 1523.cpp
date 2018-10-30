#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 1010
int a[maxn];
char s[maxn];
int n,p;
bool flag = false;
void dfs(int x,int y,int res[],int rt)
{
	if(flag) return ;
	int i;
	res[x] = y;
	if(x==n)
	{
		flag = true;
		return ;
	}
	if(rt)
	{
		for(i=0;i<p;i++)
		{
			if(x>=1 && i==res[x]) continue;
			if(x>=2 && i==res[x-1]) continue;
			dfs(x+1,i,res,1);
		}
	}
	else
	{
		if(x==n-1)
		{
			for(i=a[x+1]+1;i<p;i++)
			{
				if(x>=1 && i==res[x]) continue;
				if(x>=2 && i==res[x-1]) continue;
				if(i==a[x+1]+1) dfs(x+1,i,res,0);
				else dfs(x+1,i,res,1);
			}
		}
		else
		{
			for(i=a[x+1];i<p;i++)
			{
				if(x>=1 && i==res[x]) continue;
				if(x>=2 && i==res[x-1]) continue;
				if(i==a[x+1]) dfs(x+1,i,res,0);
				else dfs(x+1,i,res,1);
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&p);
	scanf("%s",s);
	int m = strlen(s);
	int i;
	for(i=0;i<m;i++)
	{
		a[i+1] = s[i] - 'a';
	}
	int res[maxn];
	dfs(0,0,res,0);
	if(!flag) printf("NO\n");
	else 
	{
		for(i=1;i<=m;i++) printf("%c",res[i]+'a');
		printf("\n");
	}

}