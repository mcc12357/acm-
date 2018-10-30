#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	char a[1005],b[1005];
	while(~scanf("%s %s",a,b)&&(a[0]!='0'||b[0]!='0'))
	{
		int m,n;
		if(a[0]=='-' && b[0]!='-') printf("a<b\n");
		else if(a[0]!='-'&&b[0]=='-') printf("a>b\n");
		else if(a[0]!='-'&& b[0]!='-')
		{
			m = strlen(a);
			n = strlen(b);
			if(m>n) printf("a>b\n");
			else if(m<n) printf("a<b\n");
			else 
			{
				if(strcmp(a,b)>0) printf("a>b\n");
				else if(strcmp(a,b)<0) printf("a<b\n");
				else printf("a==b\n");
			}
		}
		else if(a[0]=='-'&& b[0]=='-')
		{
			m = strlen(a);
			n = strlen(b);
			if(m>n) printf("a<b\n");
			else if(m<n) printf("a>b\n");
			else 
			{
				if(strcmp(a,b)>0) printf("a<b\n");
				else if(strcmp(a,b)<0) printf("a>b\n");
				else printf("a==b\n");
			}
		}
	}
	return 0;
}