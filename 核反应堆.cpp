#include<iostream>
using namespace std;
#include<stdio.h>
_int64 f1(int n)
{
	_int64 f2(int m);
	if(n==0) return 1;
	return (3*f1(n-1)+2*f2(n-1));
}
_int64 f2(int n)
{
	if(n==0) return 0;
	return (f1(n-1)+f2(n-1));
}
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==-1) break;
		printf("%I64d",f1(n));
		printf(",");
		printf("%I64d\n",f2(n));
	}
}