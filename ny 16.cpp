#include<iostream>
using namespace std;
#include<algorithm>
#include<stdio.h>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
struct shape
{
	int x;
	int y;
};
bool cmp(shape a,shape b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
int main()
{

	int n;
	scanf("%d",&n);
	while(n--)
	{
		shape a[1001];
		int f[1005];
		fill(f,f+1001,1);
		int t;
		scanf("%d",&t);
		int i,j;
		for(i=0;i<t;i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
			if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		}
		sort(a,a+t,cmp);
		for(i=0;i<t;i++)
		{
			for(j=0;j<i;j++) if(a[i].y>a[j].y && a[i].x > a[j].x) f[i] = max(f[i],f[j] + 1); 
		}
		int kk = f[0];
		for(i=0;i<t;i++) if(kk<f[i]) kk = f[i];
		printf("%d\n",kk);

	}
	return 0;
}