#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int n,m,i;
	int a[101],b[101];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
	for(i=0;i<m;i++)
	{
		int x,y,j;
		scanf("%d %d",&x,&y);
		int ans = 0;
		for(j=0;j<n;j++)
		{
			if(a[j]>x && b[j]>y || a[j]<x && b[j]<y) ans++;
		}
		printf("%d\n",2*ans-n);
	}
	return 0;
}