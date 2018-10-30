#include<iostream>
using namespace std;
#include<stdio.h>
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
		int x,y;
		scanf("%d %d",&x,&y);
		int a,b;
		a = gcd(x,y);
		b = x * y / a;
		printf("%d %d\n",a,b);
	}
	return 0;
}