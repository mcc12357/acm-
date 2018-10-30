#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	_int64 f1[35],f2[35];
	int n;
	for(int i=0;i<35;i++)
	{
		f1[i]=0;
		f2[i]=0;
	}
	while(1)
	{
		cin>>n;
		int k = 0;
		if(n==-1) break;
		f1[0] = 1;
		f2[0] = 0;
		if(f1[n]!=0&&f2[n]!=0)
		{
			printf("%I64d",f1[n]);
			printf(", %I64d\n",f2[n]);
			k=1;
		}
		if(k) continue;
		for(int i=1;i<=n;i++)
		{
			f1[i] = 3*f1[i-1] + 2*f2[i-1];
			f2[i] = f1[i-1] + f2[i-1];
		}
		printf("%I64d",f1[n]);
		printf(", %I64d\n",f2[n]);
	}
}