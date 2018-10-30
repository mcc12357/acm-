#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
struct List
{
	char a[55];
	int res;
}list[105];
bool cmp(List x,List y)
{
	return x.res<y.res;
}
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<m;i++)
	{
		scanf(" %s",list[i].a);
		for(j=0;j<n;j++)
		{
			int k;
			for(k=j+1;k<n;k++)
			{
				if(list[i].a[k]<list[i].a[j]) list[i].res++;
			}
		}
	}
	sort(list,list+m,cmp);
	for(i=0;i<m;i++)
	{
		printf("%s\n",list[i].a);
	}
}