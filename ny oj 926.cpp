#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a*(100-b)==0 && 100*(100-a)) 
		{
			printf("0/1 ");
			printf("%d/%d\n",100*(100-a)/gcd(100*(100-a),(10000-a*b)),(10000-a*b)/gcd(100*(100-a),(10000-a*b)));
		}
		else if(100*(100-a)==0 && a*(100-b))
		{
			printf("%d/%d ",a*(100-b)/gcd(a*(100-b),(10000-a*b)),(10000-a*b)/gcd(a*(100-b),(10000-a*b)));
			printf("0/1\n");
		}
		else if(a*(100-b)==0 && 100*(100-a)==0)
		{
			printf("0/1 ");
			printf("1/1\n");
		}
		else 
		{
			printf("%d/%d ",a*(100-b)/gcd(a*(100-b),(10000-a*b)),(10000-a*b)/gcd(a*(100-b),(10000-a*b)));
			printf("%d/%d\n",100*(100-a)/gcd(100*(100-a),(10000-a*b)),(10000-a*b)/gcd(100*(100-a),(10000-a*b)));
		}
	}
	return 0;
}