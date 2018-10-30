#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#define maxn 200010
int n,a,k;
int m;
int b[maxn];
bool f(int x)
{
	int i;
	int c[maxn];
	for(i=0;i<=x;i++) c[i] = b[i];
	c[x+1] = 1;
	c[x+2] = n;
	int len = x + 3;
	sort(c,c+len);
	int num = 0;
	for(i=1;i<len;i++)
	{
		if(c[i]==c[i-1]) continue;
		if(i==1 || i==len-1) num += (c[i] - c[i-1] + 1) / (a + 1);
		else num += (c[i] - c[i-1]) / (a + 1);
	}
	return num<k;
}
int main()
{
	while(~scanf("%d %d %d %d",&n,&k,&a,&m))
	{
		int i;
		for(i=0;i<m;i++) scanf("%d",&b[i]);
		int l = 0,r = m - 1;
		while(r-l>1)
		{
			int mid = (l + r) / 2;
			if(f(mid)) r = mid;
			else l = mid;
		}
		if(f(l)) printf("%d\n",l+1);
		else if(f(r)) printf("%d\n",r+1);
		else printf("-1\n");
	}
}