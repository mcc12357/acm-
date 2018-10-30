#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#define maxn 410
int match[maxn];
vector<int> g[maxn];
bool used[maxn];
int pass[maxn][maxn];
struct Box
{
	int length,broad,area;
}box[maxn];
//int length[maxn],broad[maxn];
bool cmp(Box x,Box y)
{
	return x.area>y.area;
}
int n;
bool dfs(int v)
{
	used[v] = true;
	int i;
	for(i=0;i<g[v].size();i++)
	{
		int u = g[v][i],w = match[u];
		if(w<0 || !used[w]&&dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) 
	{
		scanf("%d %d",&box[i].length,&box[i].broad);
		box[i].area = box[i].broad * box[i].length;
	}
	sort(box,box+n,cmp);
	for(i=0;i<n;i++)
	{
		box[i+n].length = box[i].length;
		box[i+n].broad = box[i].broad;
	}
	int j;
	for(i=0;i<n;i++)
	{
		for(j=n;j<2*n;j++)
		{
			if(pass[i][j]) continue;
			if(box[i].length==box[j].length && box[i].broad==box[j].broad && j-i!=n)
			{
				g[i].push_back(j);
				g[j].push_back(i);
				pass[j-n][i+n] = 1;
			}
			if(box[i].length<=box[j].length && box[i].broad<=box[j].broad && j-i!=n)
			{
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	memset(match,-1,sizeof(match));
	int res = 0;
	for(i=0;i<2*n;i++)
	{
		if(match[i]<0)
		{
			memset(used,0,sizeof(used));
			if(dfs(i)) res++;
		}
	}
	int sum = 0;
	for(i=0;i<n;i++)
	{
		if(match[i]!=-1) continue;
		sum += box[i].area;
	}
	printf("%d\n",sum);

}