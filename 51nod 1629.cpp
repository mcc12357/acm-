#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
double pi = 3.141592653;
int main()
{
	double s;
	scanf("%lf",&s);
	double res = pow(s*s*s/72/pi,0.5);
	printf("%.6f\n",res);
}