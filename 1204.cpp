#include<iostream>
using namespace std;
double f(double x,int i)
{
	double sum=1;
	while(i--) sum*=x;
	return sum;
}
int main()
{
	int m,n;
	double p,q;
	while(scanf("%d %d %lf %lf",&n,&m,&p,&q)!=EOF)
	{
		double sum=0.0;
		int i;
		for(i=0;i<=n-1;i++)
		{
			sum+=f((1-p)*q,i)*f(p*(1-q),i+m)*1/(p+q-2*p*q);
		}
		printf("%.2lf\n",sum);
	}
}
