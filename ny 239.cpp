//������ƥ��ģ��
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
int const M = 505;
vector<int> v[M];//����ĳ���˿��������Ϣ
bool mark[M];//����ĳһ���Ƿ��Ѿ����
int link[M];//link[i]�����i��Եĵ�
int n,k;//nΪ��Ů��������kΪ�ɹ��������
bool findpath(int i)
{
	int term;
	int j;
	for(j=0;j<v[i].size();j++)
	{
		term = v[i][j];
		if(!mark[term])
		{
			mark[term] = true;
			if(!link[term] || findpath(link[term]))
			{
				link[term] = i;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int T,i, a,b,res;
	scanf("%d",&T);
	while(T--)
	{
		memset(link,0,sizeof(0));
		scanf("%d %d",&n,&k);
		for(i=1;i<=k;i++)
		{
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
		}
		res = 0;
		for(i=1;i<=n;i++)
		{
			memset(mark,0,sizeof(0));
			if(findpath(i)) res++;

		}
		printf("%d\n",res);
	}
	return 0;
}