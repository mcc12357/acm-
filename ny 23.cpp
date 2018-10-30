#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		if(n%(m+1)==0) printf("Lose\n");
		else printf("Win\n");
	}
}	
