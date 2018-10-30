#include<iostream>
using namespace std;
#include<string.h>
#include<string>
#include<vector>
int n,m,s;
int map[105][105];
int visited[105];
int no[105];
int res[15];
int count;
vector<int> g[105];
bool judge(int now,int k)
{
	int i;
	for(i=0;i<=k;i++) if(!map[res[i]][now]) return false;
	return true;
}
void dfs(int x,int i)
{
	res[i] = x;
	visited[x] = 1;
	if(i==s-1)
	{
		count++;
		return ;
	}
	int j,k;
	for(k=0;k<g[x].size();k++)//一开始只用邻接矩阵存，这里每次循环到n,导致超时，用邻接表就不会，因为是稀疏图
	{
		j = g[x][k]; 
		if(!no[j] && !visited[j] && judge(j,i))
		{
			visited[j] = 1;
			dfs(j,i+1);
			visited[j] = 0;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&s);
		int i,a,b;
		for(i=0;i<105;i++) g[i].clear();
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a][b] = 1;
			map[b][a] = 1;
			g[a].push_back(b);//很重要的剪枝，不将b连到a,这样每次取边都按从小到大的拓扑序来取，这样就不会重复，比如枚举的一个集合1,3,4,6，按照这个方法就不会出现3,1,4,6、3,1,6,4等等多种情况
		}
		memset(visited,0,sizeof(visited));
		memset(no,0,sizeof(no));
		count = 0;
		for(i=1;i<=n;i++)
		{
			memset(visited,0,sizeof(visited));
			memset(res,0,sizeof(res));
			dfs(i,0);
			no[i] = 1;
		}
		printf("%d\n",count);

	}
}