#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1001000
int move[maxn];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int tmax = 0;
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		tmax = max(tmax,a);
		move[a]++;
	}
	int res = 0;
	for(i=0;i<=tmax+100;i++)
	{
		if(move[i]&1) res++;
		move[i+1] += move[i] >> 1;
	}
	printf("%d\n",res);
}
/*
13
0 0 4 5 5 5 5 5 5 5 5 5 5
*/