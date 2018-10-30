#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
float val[500],grade[500];
int k = 0;
int main()
{
	float m,n;
	while(~scanf("%f %f",&m,&n) && (m||n))
	{
		val[k] = m;
		grade[k] = n;
		k++;
	}
	int i;
	float ans = 0;
	float totalval = 0;
	for(i=0;i<k;i++)
	{
		ans += val[i] * grade[i];
		totalval += val[i];
	}
	printf("%f\n",ans/totalval);
}