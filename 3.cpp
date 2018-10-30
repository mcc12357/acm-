#include<stdio.h>
int g(int m)
{
	int i,sum=1;
	for(i=1;i<=m;i++) sum*=i;
	return sum;
}

int f(int m)
{
	int k,i,sum=0;
	k=g(m);
	for(i=1;i<=m;i++) sum+=(g(m)/g(i)/g(m-i))*f(m-i);
	return (k-sum);
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