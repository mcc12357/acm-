#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n%7==0 || n/7*7+2==n) printf("B\n");
		else printf("A\n");
	}
}