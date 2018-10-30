#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int m,n;//m��n�еľ���
int a[100][100];//a���������
bool isres;//�Ƿ���ڽ�
int res;//��ǰ�ǵڼ����

//�ҵ�����ӡ����ĺ���
void print()
{
	int sum = 0;
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++) sum += a[i][j];
	if(sum==0) return ;
	printf("result %d is :\n",res);
	res++;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	isres = true;
}

//�ж�λ��(x,y)�������Ƿ������г����Ķ���
bool judge(int x,int y)
{
	int sum = 0;
	sum = a[x][y] + a[x-1][y] + a[x+1][y] + a[x][y-1] + a[x][y+1];
	if(sum % 2) return false;
	return true;
}

//��ǰ��(x,y)��������ֵk�������µݹ�
void dfs(int x,int y,int k)
{
	a[x][y] = k;
	if(x>1 && !judge(x-1,y)) return ;//�����һ�м�(x-1,y)���Ѿ��������г�����壬��ǰ�����ݹ�
	if(x==m)//�������һ�е����
	{
		if(y>1 && !judge(x,y-1)) return ;//���ǰһ�м�(x,y-1)���Ѿ��������г�����壬��ǰ�����ݹ�
		if(y==n)//�Ѿ������һ�������ݹ�������жϽ���������ʹ�ӡ
		{
			if(!judge(x,y)) return ;
			print();
		}
		else//�����ݹ�
		{
			dfs(x,y+1,0);
			dfs(x,y+1,1);
		}
		return ;
	}
	else//�������һ�еĽ��
	{
		if(y==n)//�������һ�У��ݹ����һ�е�һ����ʼ
		{
			dfs(x+1,1,0);
			dfs(x+1,1,1);
		}
		else//����ӱ�����һ�п�ʼ
		{
			dfs(x,y+1,0);
			dfs(x,y+1,1);
		}
	}
}
int main()
{
	while(~scanf("%d %d",&m,&n))
	{
		memset(a,0,sizeof(a));//��ʼ��a����Ϊȫ0,����1-m,����1-nΪ��г����0��0���Լ�m+1��,n+1��Ϊ�ӵ�һȦ0
		isres = false;//��ʼ��Ϊ�٣�˵����δ�ҵ���
		res = 1;//��ʼ��Ϊ1��˵����һ���
		dfs(1,1,0);//��һ��λ��(1,1)����0��ʼ�ݹ�
		dfs(1,1,1);//��һ��λ��(1,1)����1��ʼ�ݹ�
		if(!isres) printf("no result!\n");//δ�ҵ�������޽�
	}
}