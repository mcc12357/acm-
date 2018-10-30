#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
void exgcd(_int64 a,_int64 b,_int64 &d,_int64 &x,_int64 &y)
{
	if(b==0)
	{
		x = 1,y = 0;
		d = a;
		return;
	}
	else
	{
		exgcd(b,a%b,d,x,y);
		_int64 temp = x;
		x = y;
		y = temp - (a/b) * y;
	}
}
int main()
{
	_int64 x,y,m,n,l;
	scanf("%I64d %I64d %I64d %I64d %I64d",&x,&y,&m,&n,&l);
		_int64 d,X,Y;//d为最大公约数
		exgcd(n-m,l,d,X,Y);
		if((x-y)%d || m==n) printf("Impossible\n");//注意不能忘了m=n情况
		else
		{
			X *= (x-y) / d;
			X = (X%(l/d)+l/d)%(l/d);
			printf("%I64d\n",X);
		}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	return 0;
}