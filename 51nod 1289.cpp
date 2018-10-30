#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 100010
int a[maxn],b[maxn],lmax[maxn],rmax[maxn];
bool dead[maxn];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
	int tm = 0;
	memset(dead,0,sizeof(dead));
	for(i=0;i<n;i++)
	{
		if(b[i]==1)
		{
			tm = max(tm,a[i]);
		}
		else
		{
			if(a[i]>tm) tm = 0;
		}
		rmax[i] = tm;
	}
	tm = 0;
	for(i=n-1;i>=0;i--)
	{
		if(b[i]==0)
		{
			tm = max(tm,a[i]);
		}
		else
		{
			if(a[i]>tm) tm = 0;
		}
		lmax[i] = tm;
	}
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			if(i==0) continue;
			if(a[i]>rmax[i-1]) dead[i] = false;
			else dead[i] = true;
		}
		else
		{
			if(i==n-1) continue;
			if(a[i]>lmax[i+1]) dead[i] = false;
			else dead[i] = true;
		}
	}
	int res = 0;
	for(i=0;i<n;i++) if(!dead[i]) res++;
	printf("%d\n",res);
}