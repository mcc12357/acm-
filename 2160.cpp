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
		int m=1,k=0,a=0,sum=0;//m表示出生1天的小猪，k表示出生第二天的小猪,a表示出生3天的小猪
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