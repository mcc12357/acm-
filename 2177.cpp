#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,i,m;
	double k;
	while(scanf("%d %d",&a,&b)!=EOF && a && b)
	{
		if(a>b) swap(a,b);
		k=(sqrt(5.0)+1)/2;
		if(a == (int)((b-a)*k)) printf("0\n");
		else 
		{
			printf("1\n");
			//�����ȡ����ͬ����ʯ��ʣ��ʯ��
			m=b-a;
			for(i=1;i<a;i++)//i��ʾa��ʣ��ʯ��
			{
				if(i == (int)((b-a)*k)) printf("%d %d\n",i,i+m);
			}
			//�������һ����ȡ�����ʯ�ӵ������ֻ�����ڶ��b����ȡ������a����ȡ����b-a��󣬲����ܱ�Ϊ�������
			for(i=0;i<b;i++)//i��ʾbȡ���ʣ�µ�ʯ��
			{
				if(a>i)//ע�����b�����ʣ�µ�С��a������Ҫ����
				{	
					if(i == (int)((a-i)*k)) printf("%d %d\n",i,a);
				}
				else if(a == (int)(i-a)*k) printf("%d %d\n",a,i);
			}
		}
	}
}