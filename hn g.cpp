#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 50100
struct S
{
	int a;
	int rank;
}s[maxn];
bool cmp(S x,S y)
{
	return x.a<y.a;
}
int b[maxn];
int c[maxn];
int lmin[maxn];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&s[i].a);
			s[i].rank = i;
		}
		sort(s,s+n,cmp);
		for(i=0;i<n;i++)
		{
			b[s[i].rank] = i;
		}
		for(i=0;i<n;i++)
		{
			c[b[i]] = i;
		}
		lmin[0] = 50000;
		for(i=1;i<n;i++)
		{
			lmin[i] = min(lmin[i-1],c[i-1]);
		}
		int res = 0;
		for(i=0;i<n;i++) 
		{
			res = max(res,c[i] - lmin[i]);
		}
		printf("%d\n",res);
	}
	
}