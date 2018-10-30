#include<iostream>
using namespace std;
int main()
{
	int t,a[100],b[100],i;
	double area;
	while(scanf("%d",&t)!=EOF && t)
	{
		area=0;
		for(i=0;i<t;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
		}
		for(i=0;i<t-1;i++)
		{
			area+=(a[i]*b[i+1]-a[i+1]*b[i]);
		}
		area+=(a[t-1]*b[0]-a[0]*b[t-1]);
		printf("%.1lf\n",0.5*area);
	}
}