#include<iostream>
using namespace std;
int min(int m,int n)
{
	if(m<n) return m;
	else return n;
}
int max(int m,int n)
{
	if(m>n) return m;
	else return n;
}
int  main()
{
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		int k1=min(m,n);
		int k2=max(m,n);
		int i=k1%8;//i��ʾ����
		int j=k1/8;//j��ʾ��
		int res;//res��ʾ�����Ӧ��
		if(i==0)
		{
			res=13+j*;
			if(k2==res) printf("B\n");
			else printf("A\n");
		}
		if(i==1)
		{
			res=2+13*
		}
	}
}