#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<cmath>
#define maxn 110
char a[maxn][maxn];
int money[maxn],v[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int i;
		int ans = 0;
		double res = 0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s %d %d",a[i],&money[i],&v[i]);
			if(v[i]<200) continue;
			double tm;
			int day = v[i] / 200;
			if(v[i]<=1000)
			{
				tm = day * 1.0 / money[i];
				if((res-tm<1e-6&&fabs(res-tm)>1e-6) || (fabs(res-tm)<1e-6)&&v[ans]<v[i])
				{
					ans = i;
					res = tm;
				}
			}
			else
			{
				tm = 5.0 / money[i];
				if((res-tm<1e-6&&fabs(res-tm)>1e-6) || ((fabs(res-tm)<1e-6)&&v[ans]<v[i]))
				{
					ans = i;
					res = tm;
				}
			}
		}
		printf("%s\n",a[ans]);
	}
}