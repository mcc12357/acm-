#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1000
void reverse(char b[],int s,int t)
{
	int mid = (t - s) / 2;
	int i;
	for(i=0;i<=mid;i++) swap(b[s+i],b[t-i]);
}
int main()
{
	char a[maxn];
	//scanf("%s",a);
	gets(a);
	char b[maxn];
	int m = strlen(a);
	int i,n = 0;
	for(i=0;i<m;i++)
	{
		if(a[i]!=' ' || a[i]==' ' && i>0 && a[i-1]!=' ')
		{
			b[n++] = a[i];
		}
	}
	b[n] = ' ';
	int j;
	i = 0;
	for(j=1;j<=n;j++)
	{
		if(b[j]==' ')
		{
			reverse(b,i,j-1);
			i = j + 1;
		}
	}
	for(i=0;i<n;i++) printf("%c",b[i]);
	printf("\n");
}