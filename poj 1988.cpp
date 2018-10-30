#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 30005
int sum[maxn],under[maxn];
int par[maxn];
void init()
{
	int i;
	for(i=1;i<=30000;i++) 
	{
		par[i] = i;
		sum[i] = 1;
	}
}
int getfa(int x)
{
	if(par[x]==x) return x;
	int tx = getfa(par[x]);
	under[x] += under[par[x]];
	par[x] = tx;
	return tx;
}
void merge(int x,int y)
{
	int a = getfa(x);
	int b = getfa(y);
	if(a==b) return ;
	par[a] = b;
	under[a] = sum[b];
	sum[b] += sum[a];
}
int main()
{
	int p;
	init();
	scanf("%d",&p);
	while(p--)
	{
		char str[5];
		scanf("%s",str);
		if(str[0]=='M')
		{
			int a,b;
			scanf("%d %d",&a,&b);
			merge(a,b);
		}
		else
		{
			int c;
			scanf("%d",&c);
			getfa(c);
			printf("%d\n",under[c]);
		}

	}
}