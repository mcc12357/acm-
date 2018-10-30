#include<iostream>
using namespace std;
#include<stdio.h>
const int inf = 1100000000;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	int n,l,a;
	scanf("%d %d",&n,&l);
	int i;
	int res1 = 0;
	int res2 = 0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		int tm1 = min(a,l-a);
		int tm2 = max(a,l-a);
		res1 = max(res1,tm1);
		res2 = max(res2,tm2);
	}
	printf("%d %d\n",res1,res2);

}