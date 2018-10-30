#include<iostream>
using namespace std;
#include<stdio.h>
#define pi 3.14
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=1;i<=t;i++)
	{
		double x,y;
		scanf("%lf %lf",&x,&y);
		int year;
		year = 0.5 * pi * (x * x + y * y) / 50 + 1;
		printf("Property %d: This property will begin eroding in year %d.\n",i,year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}