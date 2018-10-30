#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
char s[1000];
char a[1000];
int main()
{
	gets(s);
	int i;
	int m = strlen(s);
	for(i=0;i<m;i++)
	{
		if(s[i]==' ') break;
		a[i] = s[i];
	}
	printf("Of course, forgive %s.\n",a);
}