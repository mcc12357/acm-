#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 1010
int n,m;
int par[maxn],rank[maxn];
void init(int x)
{
	int i;
	for(i=1;i<=x;i++)
	{
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x)
{
	if(par[x]==x) return x;
	else return par[x] = find(par[x]);
}
void unit(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x==y) return ;
	if(rank[x]<rank[y]) par[x] = y;
	else
	{
		par[y] = x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}
bool same(int x,int y) 
{
	return find(x)==find(y);
}
int main()
{
	while(~scanf("%d",&n) && n)
	{
		scanf("%d",&m);
		int i;
		init(n);
		int ans = 0;
		for(i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			unit(a,b);
		}
		for(i=1;i<=n;i++) if(par[i]==i) ans++;
		printf("%d\n",ans-1);
	}
}