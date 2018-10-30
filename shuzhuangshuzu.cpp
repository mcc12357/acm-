#include<iostream>
using namespace std;
#include<stdio.h>
#define maxn 500
int bit[maxn];
int n = 100;
int sum(int i)
{
	int s = 0;
	while(i>0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i] += x;
		i += i & -i;
	}
}
int main()
{
	add(5,1);
	printf("%d\n",sum(10));
}