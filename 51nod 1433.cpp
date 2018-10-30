#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n;
int a[2];
int main()
{
	scanf("%d",&n);
	int tm;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&tm);
		if(tm==0) a[0]++;
		else a[1]++;
	}
	if(!a[0]) printf("-1\n");
	else
	{
		int t = a[1] / 9;
		int j;
		bool flag = true;
		for(i=1;i<=t;i++)
		{
			flag = false;
			for(j=1;j<=9;j++) printf("5");
		}
		if(!flag) for(i=1;i<=a[0];i++) printf("0");
		else printf("0");
		printf("\n");
	}
	
}