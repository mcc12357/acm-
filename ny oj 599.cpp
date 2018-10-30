#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m;
		scanf("%d",&m);
		if(m<10) printf("1\n");
		else if(m%5==0)
		{
			printf("%d\n",(m-10)/5+1);
		}
		else 
		{
			printf("%d\n",((m+5)/5*5-10)/5+1);
		}
	}
	return 0;
}
