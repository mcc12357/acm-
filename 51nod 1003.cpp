#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n;
int main()
{
	scanf("%d",&n);
	int ans = 0;
	while(n)
	{
		ans += n / 5;
		n /= 5;
	}
	printf("%d\n",ans);
}