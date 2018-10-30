#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0) break;
		char a[1001][16];
		int b[1001];
		int i,j;
		for(i=0;i<1001;i++) b[i]=0;
		for(i=0;i<n;i++)
			scanf("%s",&a[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(!strcmp(a[i],a[j])) 
				{
					b[i]++;
				}
			}
		}
		int p=0,t;
		t=b[0];
		for(i=0;i<n;i++) 
			if(b[i]>t)
			{
				p=i;
				t=b[i];
			}
		printf("%s\n",a[p]);
	}
}