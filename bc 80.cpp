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
		scanf("%d",&n);
		int i,kk = 0,tt = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			if(m==1) kk = 1;
			if(m==0) tt = 1;
		}
		if(kk && tt) printf("YES\n");
		else printf("NO\n");
	}
}