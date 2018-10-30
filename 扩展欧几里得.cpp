#include<iostream>
using namespace std;
#include<stdio.h>
typedef _int64 l;
void exgcd(l a,l b,l & d,l & x,l & y)
{
	if(b==0)
	{
		x = 1;
		y = 0;
		d = a;
		return;
	}
	else
	{
		exgcd(b,a%b,d,x,y);
		l temp = x;
		x = y;
		y = temp - (a/b) * y;
	}
}
int main()
{
	l a,b,d,x,y;
	scanf("%I64d %I64d",&a,&b);
	//printf("%I64d %I64d\n",a,b);
	exgcd(a,b,d,x,y);
	printf("%I64d %I64d\n",x,y);
}