#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int res[100];
bool f(int x)
{
	int n = x;
	int k = 0;
	while(n)
	{
		res[k++] = n % 10;
		n /= 10;
	}
	int i,j;
	int ans = 0;
	for(i=0;i<k;i++)
	{
		int tm = 1;
		for(j=0;j<k;j++)
		{
			tm *= res[i];
		}
		ans += tm;
	}
	return ans==x;
}
int main()
{
	int m;
	scanf("%d",&m);
	int i;
	for(i=m;;i++)
	{
		if(f(i)) break;
	}
	printf("%d\n",i);
}