#include<iostream>
using namespace std;
#include<stdio.h>
int fa[100005],rank[100005];
int n,m;
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		fa[i] = i;
		rank[i] = 0;
	}
}
int getfather(int x)
{
	if(x==fa[x]) return x;
	int oldfa = fa[x];
	fa[x] = getfather(fa[x]);
	rank[x] = (rank[x]+rank[oldfa]) % 2;
	return fa[x];
}
void unionset(int x,int y)
{
	int fx,fy;
	fx = getfather(x);
	fy = getfather(y);
	if(fx==fy) return;
	fa[fx] = fy;
	rank[fx] = (rank[x] + rank[y] + 1) % 2;
	return ;
}
int istrue(int x,int y)
{
	if(rank[x]==rank[y]) return 0;
	else return 1;
}
int same(int x,int y)
{
	return getfather(x)==getfather(y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[5];
		scanf("%d %d",&n,&m);
		int i,x,y;
		init();
		for(i=1;i<=m;i++)
		{
			scanf("%s",str);
			scanf("%d %d",&x,&y);
			if(str[0]=='D')
			{
				unionset(x,y);
			}
			else
			{
				if(!same(x,y)) printf("Not sure yet.\n");
				else
				{
					if(istrue(x,y)) printf("In different gangs.\n");
					else printf("In the same gang.\n");
				}
			}
		}
	}
}