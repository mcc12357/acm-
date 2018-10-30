#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a[1000001],f[1000001];
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		f[0] = a[0];
		for(i=1;i<n;i++) if(f[i-1]>0) f[i] = f[i-1] + a[i];
		else f[i] = a[i];
		int max = f[0];
		for(i=0;i<n;i++) if(f[i] > max) max = f[i];
		printf("%d\n",max);
	}
}