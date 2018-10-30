#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int k = 0,temp;
		while(n)
		{
			temp = n & 1;
			if(temp==1) k++;
			n /= 2;
		}
		if(k%2==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}