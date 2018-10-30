#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
const double pi = 3.141592653;
const double e = 2.71828182845;
double eps,a,b,h,T,S;
int n;
double f(double x)
{
	//return 0.2 + 25 * x - 200 * x * x + 675 * x * x * x - 900 * x * x * x * x + 400 * x * x * x * x * x;
	//return x;
	return sin(x);
	//return cos(1/x)/x;
	//return (10 * pow(e,-x) * sin(2 * pi * x)) * (10 * pow(e,-x) * sin(2 * pi * x));
}
int main()
{
	scanf("%lf %lf %lf",&eps,&a,&b);
	n = 1;
	int count = 2;
	h = b - a;
	T = 0.5 * h * (f(a) * f(b));
	S = 0.5 * (T + h * (f(a+0.5*h)));
	int i;
	while(fabs(S-T)>eps)
	{
		T = S;
		n = 2 * n;
		h = 0.5 * h;
		for(i=0;i<n;i++) S += h * f(a + 0.5 * h + i * h);
		S *= 0.5;
		count++;
	}
	printf("%d %.15f\n",count,T);
}