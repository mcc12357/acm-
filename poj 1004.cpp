#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	double m = 0,t;
	int i;
	for(i=1;i<=12;i++) {scanf("%lf",&t);m += t;}
	printf("$%.2f\n",m/12);
}