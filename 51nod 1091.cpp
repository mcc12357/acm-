#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#define maxn 50010
struct Line
{
	int l,r;
}line[maxn];
int n;
bool cmp(Line x,Line y)
{
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int lmin[maxn];
int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&line[i].l,&line[i].r);
	}
	sort(line,line+n,cmp);
	int tm = line[n-1].l;
	for(i=n-1;i>=0;i--)
	{
		tm = min(tm,line[i].l);
		lmin[i] = tm;
	}
	int res = 0;
	for(i=0;i<n-1;i++)
	{
		res = max(res,line[i].r-max(line[i].l,lmin[i+1]) );
	}
	printf("%d\n",res);
}