#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef _int64 ll;
#define maxn 1e18+100
ll a[1000000];//����2,3,5�������<1e18�������ᳬ��64*64*64��
int main()
{
	int t;
	scanf("%d",&t);
	ll i,j,p,k = 0;
	for(i=1;i<maxn;i*=2)
	{
		for(j=1;i*j<maxn;j*=3)//ע������������ѭ�����ж�����������������жϿ��ܻ����
		{
			for(p=1;i*j*p<maxn;p*=5)
			{
				if(i*j*p<maxn) a[k++] = i * j * p;
			}
		}
	}
	sort(a,a+k);
	//printf("%I64d %I64d %I64d\n",a[0],a[1],k);
	while(t--)
	{
		ll n;
		scanf("%I64d",&n);
		printf("%I64d\n",*lower_bound(a+1,a+k,n));
	}
}
