#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#define maxn 10010
double a[maxn];
double sum[maxn];
const double inf = 1000000000000;
double min(double x,double y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=1;i<=m;i++) scanf("%lf",&a[i]);
	sort(a+1,a+m+1);
	sum[0] = 0;
	for(i=1;i<=m;i++) sum[i] = sum[i-1] + a[i];
	double res = inf;
	for(i=1;i<=m;i++)
	{
		int e = i + n - 1;
		if(e>m) continue;
		double av = (sum[e] - sum[i-1]) / n;
		double tm = 0;
		for(j=i;j<=e;j++)
		{
			tm += (a[j] - av) * (a[j] - av);
		}
		res = min(res,tm);
	}
	printf("%I64d\n",(_int64)res);
	
}
