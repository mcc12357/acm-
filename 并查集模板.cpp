//��������Ҫ��Ӷ�������ʹһ��ͼ��Ϊ��ͨͼ�������Ϊ��ͨ��֧��һ������ͨ��֧�������ڸ��ڵ������һ
#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
int pre[1050];//pre[i]��¼i�ĸ��׽ڵ�
bool t[1050];//��Ǹ��ڵ�
int find(int x)
{
	int r = x;
	while(r!=pre[r])
	{
		r = pre[r];
	}//ͨ��������r�ĸ����ҵ�x�ĸ��ڵ�
	int i = x,j;
	while(pre[i]!=r)//��i�ĸ��׽ڵ㲻�Ǹ��ڵ�
	{
		j = pre[i];//����i�ĸ��׽ڵ�
		pre[i] = r;//��i�ĸ��׽ڵ�ֱ������ڵ�����
		i = j;//�ڴ�i�ĸ��׽ڵ���������ң�ֱ�������ӽڵ�ȫ��ֱ������ڵ�����
	}//·��ѹ����ʹ�����ӽڵ�ֱ������ڵ���������������ʹ������úܿ�
	return r;
}
void mix(int x,int y)//ʹy�ø��ڵ��Ϊx���ڵ���ӽڵ㣬��x,y֮����ͨ
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
	while(scanf("%d",&N) && N)//N�����У�M����·
	{
		scanf("%d",&M);
		for(i=1;i<=N;i++)//��ʼ�����տ�ʼ�����нڵ���ڵ�Ϊ�Լ�
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