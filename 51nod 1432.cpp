#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
int a[10010];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	int s = 0;
	int res = 0;
	sort(a,a+n);
	for(i=n-1;i>=0;i--)
	{
		if(i<s) break;
		if(a[i]+a[s]<=m)
		{
			s++;
		}
		res++;
	}
	printf("%d\n",res);
}