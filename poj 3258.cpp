#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
const int inf = 1000000005;
int rock[50005];
int t,n,m;
bool f(int x)
{
	int i;
	int num = 0;
	int last = 0;
	for(i=1;i<=n;i++)
	{
		if(rock[i]-last<x) num++;
		else last = rock[i];
		if(num>m) return false;
	}
	if(num>m) return false;
	if(num==m-1 && rock[n+1]-last<x) return false;
	return true;
}
int main()
{
	scanf("%d %d %d",&t,&n,&m);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&rock[i]);
	rock[0] = 0;
	rock[n+1] = t;
	sort(rock,rock+n+2);
	int lb = 0,ub = t;
	while(ub-lb>1)
	{
		int mid = (ub + lb) /2;
		if(f(mid)) lb = mid;
		else ub = mid;
	}
	if(f(ub)) printf("%d\n",ub);
	else printf("%d\n",lb);
}