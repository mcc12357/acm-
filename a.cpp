#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<string.h>
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==1 || n==2)
		{
			printf("No\n");
		}
		else if(n==3) printf("Yes\n");
		else
		{
			if(n%3==1) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}