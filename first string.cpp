#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1000
int num[30];
int main()
{
	char a[maxn];
	scanf("%s",a);
	int m = strlen(a);
	int i;
	for(i=0;i<m;i++) num[a[i]-'a']++;
	for(i=0;i<m;i++)
	{
		if(num[a[i]-'a']==1) break;
	}
	printf("%c\n",'a' + i);
}