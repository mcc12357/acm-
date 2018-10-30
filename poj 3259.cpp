#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
struct edge
{
	int from,to,cost;
};
int d[505];
int n,m,w;
edge es[6000];
bool find_negative_loop()
{
	memset(d,0,sizeof(d));
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<2*m+w;j++)
		{
			edge e = es[j];
			if(d[e.to]>d[e.from]+e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				if(i==n) return true;
			}
		}
	}
	return false;

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&w);
		int s,e,c,i;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&s,&e,&c);
			es[i].from = s;
			es[i].to = e;
			es[i].cost = c;
			es[i+m].from = e;
			es[i+m].to = s;
			es[i+m].cost = c;
		}
		int k = 2 * m;
		for(i=k;i<k+w;i++)
		{
			scanf("%d %d %d",&s,&e,&c);
			es[i].from = s;
			es[i].to = e;
			es[i].cost = -c;
		}
		if(find_negative_loop()) printf("YES\n");
		else printf("NO\n");

	}
}