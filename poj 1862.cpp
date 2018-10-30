#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<math.h>
bool cmp(double x,double y)
{
	if(x-y<1e-6) return true;
	return false;
}
double a[105];
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%lf",&a[i]);
	sort(a,a+n,cmp);
	while(n--)
	{
		a[n-1] = 2.0 * sqrt(a[n]*a[n-1]);
	}
	printf("%.3lf\n",a[0]);
}