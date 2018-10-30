#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j;
		scanf("%d %d",&n,&m);
		n = (n-2)*180/n;
		m = (m-2)*180/m;
		int k = 0;
		for(i=0;i<=360/n;i++)
			for(j=0;j<=360/m;j++)
			{
				if(i*n+j*m==360) k = 1;
			}
			if(k) printf("Yes\n");
			else printf("No\n");
	}
}