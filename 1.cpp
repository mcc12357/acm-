#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
int main()
{
	char a[100000];
	while(scanf("%s",a)!=EOF)
	{
		int m=strlen(a);
		int n=10*(a[m-2]-'0')+(a[m-1]-'0');
		if(n%4==0) printf("4\n");
		else printf("0\n");

	}
	return 0;

}