#include<iostream>
using namespace std;
#include<stdio.h>
int a[20],b[20];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	int i,j;
	int res = 25,tm = 0;
	for(i=0;i<20;i++) {scanf("%d",&a[i]);b[i] = a[i];}
	for(i=0;i<19;i++)
	{
		if(a[i]%2==0) continue;
		else
		{
			tm++;
			if(i+2<20) a[i+2]++;
			a[i]++;
			a[i+1]++;
		}
	}
	if(a[19]%2==0) res = min(res,tm);
	tm = 1;
	b[0]++;
	b[1]++;
	for(i=0;i<19;i++)
	{
		if(b[i]%2==0) continue;
		else
		{
			tm++;
			if(i+2<20) b[i+2]++;
			b[i]++;
			b[i+1]++;
		}
	}
	if(b[19]%2==0) res = min(res,tm);
	printf("%d\n",res);
}
/*0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0*/