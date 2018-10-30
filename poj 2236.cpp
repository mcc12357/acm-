#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
int par[1005];
int rank[1005];
int dx[1005],dy[1005];
int repair[1005];
int flag[1005];
float dis(int i,int j)
{
	return sqrt((dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]));
}
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
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
void unite(int x,int y)
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
	int n,d,i,a,b,k = 0;
	scanf("%d %d",&n,&d);
	for(i=1;i<=n;i++) scanf("%d %d",&dx[i],&dy[i]);
	init(n);
	char c;
	while(~scanf("%c",&c))
	{
		if(c=='O')
		{
			scanf("%d",&a);
			if(!flag[a]) repair[k] = a;
			flag[a] = 1;
			for(i=0;i<k;i++) 
			{
				if(!same(repair[i],repair[k]))
				{
					if(dis(repair[i],repair[k])<=d) unite(repair[i],repair[k]);
				}
			}
			k++;
		}
		if(c=='S')
		{
			scanf("%d %d",&a,&b);
			//printf("%d %d %d %d %d %d %f\n",dx[a],dy[a],dx[b],dy[b],a,b,dis(a,b));
			if(same(a,b) && flag[a] && flag[b]) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}