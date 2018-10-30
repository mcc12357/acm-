#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n;
int a[100005];
int main()
{
	int t;
	scanf("%d",&t);
	int num = 1;
	while(t--)
	{
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		a[0] = 0;
		int count = 1;
		double v = (a[n] - a[n-1]) * 1.0;
		for(i=n-1;i>0;i--)
		{
			int tmp = a[i] - a[i-1];
			double kk = tmp * 1.0;
			if(kk-v>0.000000001)
			{
				int tt;
				tt = (int)(kk / v + 0.999999999);
				v = kk * 1.0 / tt;
				count += tt;
			}
			else
			{
				count++;
				v = kk * 1.0;
			}
		}
		printf("Case #%d: %d\n",num,count);
		num++;
	}
}