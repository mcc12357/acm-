#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
double abs(double k)
{
	if(k>0) return k;
	return -k;
}
double a[300];
int main()
{
	/*double i,sum = 0;
	for(i=2;i<=300;i++) sum += 1/i;
	printf("%.3f\n",sum);*/
	double i;
	for(i=2;i<=300;i++) a[(int)i] = a[(int)(i-1)] + 1 / i;
	double m;
	while(~scanf("%lf",&m) && abs(m-0.001)>0.001)
	{
		int t = lower_bound(a,a+300,m) - a - 1;
		printf("%d card(s)\n",t);
	}
}