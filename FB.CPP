#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
typedef _int64 ll;
ll fibo[200005];
const int up = 199980;
int main()
{
	int i;
	fibo[0] = 0;
	fibo[1] = 1;
	for(i=2;i<=up;i++) fibo[i] = fibo[i-1] + fibo[i-2];
	//printf("%I64d\n",fibo[199980]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,p;

	}
}