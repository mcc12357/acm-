#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int c[100005],n;
int sum(int i)
{
	int s = 0;
	while(i>0)
	{
		s += c[i];
		i -= i & -i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=n)
	{
		c[i] += x;
		i += i & -i;
	}
}
int main()
{
	scanf("%d",&n);
	int ans = 0;
	memset(c,0,sizeof(c));
	int i;
	while(n--)
	{
		int a;
		scanf("%d",&a);
		ans += a - 1 - sum(a);
		add(a,1);
		
	}
	printf("%d\n",ans);
}