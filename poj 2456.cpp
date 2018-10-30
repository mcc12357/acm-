#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
int n,m;
int a[100005];
const int inf = 1000000005;
bool c(int d)
{
	int last = 0;
	int i;
	for(i=1;i<m;i++)
	{
		int crt = last + 1;
		while(crt<n && a[crt] - a[last]<d) crt++;
		if(crt==n) return false;
		last = crt;
	}
	return true;
	
}
int main()
{
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int lb = 0,ub = inf;
	while(ub-lb>1)
	{
		int mid = (lb + ub) / 2;
		if(c(mid)) lb = mid;
		else ub = mid;
	}
	printf("%d\n",lb);
}