#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
struct Line
{
	int l,r;
}line[10010];
bool cmp(Line x,Line y)
{
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&line[i].l,&line[i].r);
	}
	sort(line,line+n,cmp);
	int res = 1;
	int x = line[0].r;
	for(i=1;i<n;i++)
	{
		if(line[i].l>=x)
		{
			res++;
			x = line[i].r;
		}
	}
	printf("%d\n",res);
}