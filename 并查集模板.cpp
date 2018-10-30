//求至少需要添加多少条边使一个图变为连通图。其个数为连通分支减一，而联通分支个数等于根节点个数减一
#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
int pre[1050];//pre[i]记录i的父亲节点
bool t[1050];//标记根节点
int find(int x)
{
	int r = x;
	while(r!=pre[r])
	{
		r = pre[r];
	}//通过不断找r的父亲找到x的根节点
	int i = x,j;
	while(pre[i]!=r)//当i的父亲节点不是根节点
	{
		j = pre[i];//保存i的父亲节点
		pre[i] = r;//将i的父亲节点直接与根节点相连
		i = j;//在从i的父亲节点继续向上找，直到所有子节点全部直接与根节点相连
	}//路径压缩，使所有子节点直接与根节点相连，这样可以使搜索变得很快
	return r;
}
void mix(int x,int y)//使y得根节点成为x根节点的子节点，即x,y之间连通
{
	int fx = find(x),fy = find(y);
	if(fx!=fy)
	{
		pre[fy] = fx;
	}
}
int main()
{
	int N,M,a,b,i,j,ans;
	while(scanf("%d",&N) && N)//N个城市，M条道路
	{
		scanf("%d",&M);
		for(i=1;i<=N;i++)//初始化，刚开始让所有节点根节点为自己
		{
			pre[i] = i;
		}
		for(i=1;i<=M;i++)
		{
			scanf("%d %d",&a,&b);
			mix(a,b);
		}
		memset(t,0,sizeof(0));
		for(i=1;i<=N;i++)
		{
			t[find(i)] = 1;
		}
		ans = 0;
		for(i=1;i<=N;i++)
		{
			if(t[i]) ans++;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}