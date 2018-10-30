#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n,m;
int fa[30005];
int rank[30005];
void init()
{
	int i;
	for(i=0;i<=n;i++) 
	{
		fa[i] = i;
		rank[i] = 0;
	}
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void unin(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if(a==b) return ;
	if(rank[a]>rank[b]) fa[b] = a;
	else
	{
		fa[a] = b;
		if(rank[a]==rank[b]) rank[b]++;
	}
}
int main()
{
	while(~scanf("%d %d",&n,&m) && (m||n))
	{
		init();
		int i,j,a,b,k;
		for(i=0;i<m;i++)
		{
			scanf("%d",&k);
			scanf("%d",&a);
			for(j=1;j<k;j++)
			{
				scanf("%d",&b);
				unin(a,b);
				a = b;
			}
		}
		int ans = 0;
		for(i=0;i<n;i++)
		{
			if(find(i)==find(0)) ans++;
		}
		printf("%d\n",ans);
	}
}