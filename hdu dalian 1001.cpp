#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n,m,x,y;
int par[1010];
int rank1[1010];
int isroot[1010];
void init(int x)
{
	int i;
	for(i=0;i<=x;i++) 
	{
		par[i] = i;
		rank1[i] = 0;
	}
}
int find(int x)
{
	if(par[x]==x) return x;
	//else return par[x] = find(par[x]);
	while(par[x]!=x)
	{
		x = par[x];
	}
	return x;
}
void unite(int x,int y)
{
	y = find(y);
	//par[x] = y;
	x = find(x);
	if(x==y) return;
	if(rank1[x]<rank1[y]) par[x] = y;
	else
	{
		par[y] = x;
		if(rank1[x]==rank1[y]) rank1[x]++;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
int main()
{
	while(~scanf("%d %d %d %d",&n,&m,&x,&y))
	{
		init(n);
		int i;
		int a,b;
		int flag = 1;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			unite(a,b);
		}
		memset(isroot,0,sizeof(isroot));
		int root = find(a);
		isroot[root] = 1;
		for(i=1;i<=x;i++)
		{
			scanf("%d",&a);
			isroot[find(a)] = 1;
		}
		for(i=1;i<=y;i++)
		{
			scanf("%d",&a);
			isroot[find(a)] = 1;
		}
		for(i=1;i<=n;i++)
		{
			if(!isroot[find(i)])
			{
				flag = 0;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}
