#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 50010
int n,m;
int well[maxn],plate[maxn];
int main()
{
	scanf("%d %d",&n,&m);
	int i;
	scanf("%d",&well[0]);
	for(i=1;i<n;i++)
	{
		scanf("%d",&well[i]);
		if(well[i-1]<well[i]) well[i] = well[i-1];
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&plate[i]);
	}
	int t = n - 1;
	int res = 0;
	for(i=0;i<m;i++)
	{
		while(t>=0 && plate[i]>well[t]) t--;
		if(t>=0) res++;		
		t--;
		if(t<0) break;
	}
	printf("%d\n",res);
}