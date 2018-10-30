#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
int res[10000];
int main()
{
	int m;
	scanf("%d",&m);
	memset(res,0,sizeof(res));
	int i,j;
	res[0] = 1;
	for(i=1;i<=m;i++)
		for(j=0;j<=m;j++)
		{
			res[i+j] += res[j];
		}
	printf("%d\n",res[m]);
}