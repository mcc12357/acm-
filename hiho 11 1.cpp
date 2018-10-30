#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 100010
char a[maxn];
struct Show
{
	int h,i,o;
}show;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	scanf("%s",a);
	int n = strlen(a);
	int s = 0,t = 0;
	int res = maxn;
	while(t<n)
	{
		if(a[t]=='h') show.h++;
		else if(a[t]=='i') show.i++;
		else if(a[t]=='o') show.o++;
		while(show.h>=2 && show.i>=1 && show.o>=1)
		{
			if(show.h==2 && show.i==1 && show.o==1) res = min(res,t-s+1);
			if(a[s]=='h') show.h--;
			else if(a[s]=='o') show.o--;
			else if(a[s]=='i') show.i--;
			s++;
		}
		t++;
	}
	if(res!=maxn) printf("%d\n",res);
	else printf("-1\n");
}