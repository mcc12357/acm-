#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<vector>
int n,m,id;
const int maxn=205,oo=99999999;
vector<int> g[maxn];//用于存储每一个节点的孩子节点下标
bool fa[maxn];//用于标记每一个节点是否有父节点，对于没有父节点的最后都将他们连到0号节点上，即给树添上一个根
int v[maxn];//选择每一个国家所需花费
int num[maxn];//num[i]表示选取了i号节点总共得到的票数
int dp[maxn][maxn];//dp[i][j]表示选择了i号节点j个孩子所需最小花费
int dfs(int x)//返回值为x总共有多少孩子节点
{
	num[x] = 1;//选取x节点得到x本身的一票
	int i,j,k,y;
	for(k=0;k<g[x].size();k++) 
	{
		y = g[x][k];//y为x的儿子节点
		num[x] += dfs(y);
	}
	for(k=0;k<=n;k++) dp[x][k] = oo;//刚开始最小花费为无穷
	dp[x][0] = 0;//取0个孩子花费为0;
	dp[x][num[x]] = v[x];//取自己本身则得到num[x]票数，花费v[x]
	for(k=0;k<g[x].size();k++)
	{
		y = g[x][k];
		for(i=num[x];i>=0;i--)//注意此重循环顺序，类似于背包，取i个孩子，如果正过来的话每一个孩子都可以取到无穷多次
		{
			for(j=0;j<=i&&j<=num[y];j++)//j为在y节点中选择的孩子的个数
			{
				if(dp[x][i]>dp[x][i-j]+dp[y][j])
				{
					dp[x][i] = dp[x][i-j] + dp[y][j];
				}
			}
		}
	}
	return num[x];
}
int main()
{
	char str[1000];
	int i,j,ans,now;
	while(gets(str))//处理输入#就退出
	{
		if(str[0]=='#') break;
		sscanf(str,"%d %d",&n,&m);//在str字符串中取出n,m两个整数
		map<string,int> wmap;//建立map用于将每一个字符串对映一个整数下标
		for(i=0;i<=n;i++) g[i].clear();
		memset(fa,0,sizeof(fa));
		id = 0;//用于给每一个字符串对映下标
		for(i=1;i<=n;i++)
		{
			scanf("%s",str);
			if(wmap.find(str)==wmap.end()) wmap[str] = ++id;
			//如果当前国家还没出现过，则将他放入wmap中
			now = wmap[str];//now即为当前国家的下标
			scanf("%d",&v[now]);
			while(getchar()!='\n')//依次读出now国家的所有附属国家并建图
			{
				scanf("%s",str);
				if(wmap.find(str)==wmap.end()) wmap[str] = ++id;
				g[now].push_back(wmap[str]);
				fa[wmap[str]] = true;//说明此国家为某国家的附属国家
			}
		}
		v[0] = oo;//0号节点为增加到根节点，其花费初始化为无穷，即不可取
		for(i=1;i<=n;i++)//为所有不是附庸国的国家添加一个公共根
		{
			if(fa[i]) continue;
			g[0].push_back(i);
		}
		dfs(0);//从0号根节点进行dfs
		ans = oo;
		for(i=m;i<=n;i++) if(dp[0][i]<ans) ans = dp[0][i];
		printf("%d\n",ans);
	}
}