#include<stdio.h>
double g(int m)
{
	int i;
	double sum=1;
	for(i=1;i<=m;i++) sum*=i;
	return sum;
}

double f(int m)
{
	int k,i;
	double sum=0;
	k=g(m);
	if(m==0||m==1) return 0;
	if(m==2) return 1;
	for(i=1;i<=m;i++) sum+=(g(m)/g(i)/g(m-i))*f(m-i);
	return (k-sum-1);
}
int main()
{
	int t,m;
	double n1,n2,n3;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		n1=f(m);
		n2=g(m);
		printf("%.2lf",n1/n2*100);
		printf("%%\n");
	}
}