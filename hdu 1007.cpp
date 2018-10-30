#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<math.h>
const float inf = 100000000;
struct point
{
	float x,y;
};
point a[100005];
bool cmp1(point p,point q)
{
	if(p.x==q.x) return p.y<q.y;
	return p.x<q.x;
}
bool cmp2(point p,point q)
{
	if(p.y==q.y) return p.x<q.x;
	return p.y<q.y;
}
float f(int i)
{
	return sqrt((a[i].x-a[i-1].x)*(a[i].x-a[i-1].x) + (a[i].y-a[i-1].y)*(a[i].y-a[i-1].y));
}
int main()
{
	int n;
	while(~scanf("%d",&n) && n)
	{
		int i;
		for(i=0;i<n;i++) scanf("%f %f",&a[i].x,&a[i].y);
		sort(a,a+n,cmp1);
		float res = inf;
		for(i=1;i<n;i++) 
		{
			if(f(i)<res) res = f(i);
		}
		sort(a,a+n,cmp2);
		for(i=1;i<n;i++)
		{
			if(f(i)<res) res = f(i);
		}
		printf("%.2f\n",res/2);
	}
	return 0;
}