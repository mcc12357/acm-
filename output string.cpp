#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
const int m = 5;
char a[30];
void print(int s,int x,char b[],int length)
{
	b[x] = a[s];
	int i;
	if(x==length-1)
	{
		int j;
		for(j=0;j<length-1;j++)
		{
			printf("%c ",b[j]);
		}
		printf("%c\n",b[length-1]);
	}
	if(m-s<length-x) return ;
	for(i=s+1;i<m;i++)
	{
		print(i,x+1,b,length);
	}
}
int main()
{
	int i,j;
	char b[30];
	for(i=0;i<m;i++)
		a[i] = 'a' + i;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<m;j++)
		{
			print(j,0,b,i);
		}
	}
}