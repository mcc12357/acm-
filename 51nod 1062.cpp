#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int a[100010],b[100010];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	b[0] = a[0] = 0;
	b[1] = a[1] = 1;
	int i;
	for(i=2;i<=100000;i++)
	{
		if(i&1) a[i] = a[(i-1)/2] + a[(i-1)/2+1];
		else a[i] = a[i/2];
		b[i] = max(b[i-1],a[i]);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",b[n]);
	}
}