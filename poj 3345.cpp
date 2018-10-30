#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<vector>
int n,m,id;
const int maxn=205,oo=99999999;
vector<int> g[maxn];//���ڴ洢ÿһ���ڵ�ĺ��ӽڵ��±�
bool fa[maxn];//���ڱ��ÿһ���ڵ��Ƿ��и��ڵ㣬����û�и��ڵ����󶼽���������0�Žڵ��ϣ�����������һ����
int v[maxn];//ѡ��ÿһ���������軨��
int num[maxn];//num[i]��ʾѡȡ��i�Žڵ��ܹ��õ���Ʊ��
int dp[maxn][maxn];//dp[i][j]��ʾѡ����i�Žڵ�j������������С����
int dfs(int x)//����ֵΪx�ܹ��ж��ٺ��ӽڵ�
{
	num[x] = 1;//ѡȡx�ڵ�õ�x�����һƱ
	int i,j,k,y;
	for(k=0;k<g[x].size();k++) 
	{
		y = g[x][k];//yΪx�Ķ��ӽڵ�
		num[x] += dfs(y);
	}
	for(k=0;k<=n;k++) dp[x][k] = oo;//�տ�ʼ��С����Ϊ����
	dp[x][0] = 0;//ȡ0�����ӻ���Ϊ0;
	dp[x][num[x]] = v[x];//ȡ�Լ�������õ�num[x]Ʊ��������v[x]
	for(k=0;k<g[x].size();k++)
	{
		y = g[x][k];
		for(i=num[x];i>=0;i--)//ע�����ѭ��˳�������ڱ�����ȡi�����ӣ�����������Ļ�ÿһ�����Ӷ�����ȡ��������
		{
			for(j=0;j<=i&&j<=num[y];j++)//jΪ��y�ڵ���ѡ��ĺ��ӵĸ���
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
	while(gets(str))//��������#���˳�
	{
		if(str[0]=='#') break;
		sscanf(str,"%d %d",&n,&m);//��str�ַ�����ȡ��n,m��������
		map<string,int> wmap;//����map���ڽ�ÿһ���ַ�����ӳһ�������±�
		for(i=0;i<=n;i++) g[i].clear();
		memset(fa,0,sizeof(fa));
		id = 0;//���ڸ�ÿһ���ַ�����ӳ�±�
		for(i=1;i<=n;i++)
		{
			scanf("%s",str);
			if(wmap.find(str)==wmap.end()) wmap[str] = ++id;
			//�����ǰ���һ�û���ֹ�����������wmap��
			now = wmap[str];//now��Ϊ��ǰ���ҵ��±�
			scanf("%d",&v[now]);
			while(getchar()!='\n')//���ζ���now���ҵ����и������Ҳ���ͼ
			{
				scanf("%s",str);
				if(wmap.find(str)==wmap.end()) wmap[str] = ++id;
				g[now].push_back(wmap[str]);
				fa[wmap[str]] = true;//˵���˹���Ϊĳ���ҵĸ�������
			}
		}
		v[0] = oo;//0�Žڵ�Ϊ���ӵ����ڵ㣬�仨�ѳ�ʼ��Ϊ���������ȡ
		for(i=1;i<=n;i++)//Ϊ���в��Ǹ�ӹ���Ĺ������һ��������
		{
			if(fa[i]) continue;
			g[0].push_back(i);
		}
		dfs(0);//��0�Ÿ��ڵ����dfs
		ans = oo;
		for(i=m;i<=n;i++) if(dp[0][i]<ans) ans = dp[0][i];
		printf("%d\n",ans);
	}
}