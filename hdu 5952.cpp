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
	for(k=0;k<g[x].size();k++)//һ��ʼֻ���ڽӾ���棬����ÿ��ѭ����n,���³�ʱ�����ڽӱ�Ͳ��ᣬ��Ϊ��ϡ��ͼ
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
			g[a].push_back(b);//����Ҫ�ļ�֦������b����a,����ÿ��ȡ�߶�����С�������������ȡ�������Ͳ����ظ�������ö�ٵ�һ������1,3,4,6��������������Ͳ������3,1,4,6��3,1,6,4�ȵȶ������
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