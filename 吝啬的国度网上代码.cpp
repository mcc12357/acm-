//������ߵ�ÿһ���㣬ÿһ�����뾭����ǰһ����
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int pre[100005];
vector<int>v[100005];

void DFS(int cur)
{
	for(int i = 0; i < v[cur].size(); ++i)
	{
		if(pre[v[cur][i]]) continue; //�����ڸ��ڵ����������
		pre[v[cur][i]] = cur; //�����ڵ�ĸ��ڵ�Ϊcur
		DFS(v[cur][i]); //���ѵ��ף���һ��·�ϸ��ڵ�ȫ���ҳ�
	}
}

int main()
{
	int ncase, num, cur, i, x, y;
	scanf("%d", &ncase);
	while(ncase--)
	{
		memset(v, 0, sizeof(v));
		memset(pre, 0, sizeof(pre));
		scanf("%d%d", &num, &cur);
		pre[cur] = - 1; //���û�и��ڵ�
		for(i = 0; i < num - 1; ++i)
		{
			scanf("%d%d", &x, &y);
			v[x].push_back(y); //x��y������v[x]�ﱣ�����һϵ�к�x�����ĵ�
			v[y].push_back(x); //y��xҲ�϶�������ͬ��
		}
		DFS(cur); //��㿪ʼ����
		for(i = 1; i <= num; ++i)
			printf("%d ", pre[i]); //ÿ���ڵ�ĸ��ڵ㶼������pri���飬�������
	}
	return 0;
}
        