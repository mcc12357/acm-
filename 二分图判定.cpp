#include<iostream>
using namespace std;
#include<vector>
#include<string.h>
const int max_v = 100;
vector<int> g[max_v];
int color[max_v];
int v,m;//v¸öµã£¬mÌõ±ß
bool dfs(int k,int c)
{
	color[k] = c;
	int i;
	for(i=0;i<g[k].size();i++)
	{
		if(color[g[k][i]]==c) return false;
		if(color[g[k][i]]==0 && !dfs(g[k][i],-c)) return false;
	}
	return true;
}
int main()
{
	scanf("%d %d",&v,&m);
	memset(color,0,sizeof(color));
	int sign = 1,x,y,i;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(i=0;i<v;i++)
	{
		if(color[i]==0)
		{
			if(!dfs(i,1)) 
			{
				printf("No\n");
				sign = 0;
				break;
			}
		}
	}
	if(sign) printf("Yes\n");
}