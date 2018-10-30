#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef _int64 ll;
#define maxn 1e18+100
ll a[1000000];//仅又2,3,5因子组成<1e18的数不会超过64*64*64个
int main()
{
	int t;
	scanf("%d",&t);
	ll i,j,p,k = 0;
	for(i=1;i<maxn;i*=2)
	{
		for(j=1;i*j<maxn;j*=3)//注意这里面两重循环的判断条件，如果不这样判断可能会溢出
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
