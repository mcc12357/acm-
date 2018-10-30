#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#define _max 220000
int lowbit[_max];
vector<int> g[_max/2];
bool hasapple[_max/2];
int start[_max];
int end[_max];
int c[_max];
int ncount = 0;
void dfs(int v)
{
	start[v] = ++ncount;
	int i;
	for(i=0;i<g[v].size();i++) dfs(g[v][i]);
	end[v] = ++ncount;
}
int querysum(int p)
{
	int nsum = 0;
	while(p>0)
	{
		nsum += c[p];
		p -= lowbit[p];
	}
	return nsum;
}
void modify(int p,int val)
{
	while(p<=ncount)
	{
		c[p] += val;
		p += lowbit[p];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
	}
	ncount = 0;
	dfs(1);
	for(i=1;i<=ncount;i++) lowbit[i] = i & -i;
	for(i=1;i<=n;i++) hasapple[i] = 1;
	for(i=1;i<=ncount;i++)
		c[i] = i - (i - lowbit[i]);//c[i] = sum(i) - sum(i - lowbit[i])
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		char cmd[10];
		int a;
		scanf("%s %d",cmd,&a);
		if(cmd[0]=='C')
		{
			if(hasapple[a])
			{
				modify(start[a],-1);
				modify(end[a],-1);
				hasapple[a] = 0;
			}
			else
			{
				modify(start[a],1);
				modify(end[a],1);
				hasapple[a] = 1;
			}
		}
		else
		{
			int t1 = querysum(end[a]);
			int t2 = querysum(start[a]-1);
			printf("%d\n",(t1-t2)/2);
		}
	}
	return 0;

}