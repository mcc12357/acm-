#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int m=1,k=0,a=0,sum=0;//m��ʾ����1���С��k��ʾ�����ڶ����С��,a��ʾ����3���С��
		int i;
		for(i=2;i<=n;i++)
		{
			a=k;
			k=m;
			m=a+k;
			a=0;
		}
		sum=m+k;

		printf("%d\n",sum);
	}
}