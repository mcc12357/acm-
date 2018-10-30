#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#define maxn 1005
int n,k;
double up[maxn],down[maxn];
double y[maxn];
bool cmp(double x,double y)
{
	return x > y;
}
bool f(double x)
{
	int i;
	for(i=0;i<n;i++) y[i] = up[i] - x * down[i];
	sort(y,y+n,cmp);
	double sum = 0;
	for(i=0;i<n-k;i++) sum += y[i];
	return sum>=0;
}
int main()
{
	while(~scanf("%d %d",&n,&k) && (n||k))
	{
		int i;
		for(i=0;i<n;i++) scanf("%lf",&up[i]);
		for(i=0;i<n;i++) scanf("%lf",&down[i]);
		double l = 0,r = 2000000000;
		for(i=0;i<100;i++)
		{
			double mid = (l + r) / 2;
			if(f(mid)) l = mid;
			else r = mid;
		}
		printf("%d\n",(int)(100*(r+0.005)));
	}
}