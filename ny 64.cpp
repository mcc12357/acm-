#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		int i;
		for(i=0;i<=m;i++)
		{
			if(2*i+4*(m-i)==n)
			{
				printf("%d %d\n",i,m-i);
				break;
			}
		}
		if(i==m+1) printf("No answer\n");
	}
}