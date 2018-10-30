#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
//queue<int> que;
int n,k;
struct Juwel
{
	int num;
	double w;
	double v;
}juwel[100010];
struct yy
{
	double val;
	int num;
}y[100010];
bool cmp(yy x,yy y)
{
	return x.val >= y.val;
}
bool f(double x)
{
	int i;
	for(i=0;i<n;i++) 
	{
		y[i].val = juwel[i].v - x * juwel[i].w;
		y[i].num = juwel[i].num;
	}
	sort(y,y+n,cmp);
	double sum = 0;
	for(i=0;i<k;i++)
	{
		sum += y[i].val;
	}
	if(sum>=0)
	{
		//while(!que.empty()) que.pop();
		//for(i=0;i<k;i++) que.push(y[i].num);
		return true;
	}
	return false;
}
int main()
{
	while(~scanf("%d %d",&n,&k))
	{
		int i;
		//while(!que.empty()) que.pop();
		for(i=0;i<n;i++) 
		{
			scanf("%lf %lf",&juwel[i].v,&juwel[i].w);
			juwel[i].num = i + 1;
		}
		double l = 0,r = 2000000;
		while(r-l>=1e-6)
		{
			double mid = (l + r) / 2;
			if(f(mid)) l = mid;
			else r = mid;
		}
		/*while(!que.empty())
		{
			int tm = que.front();
			printf("%d ",tm);
			que.pop();
		}*/
		for(i=0;i<k;i++) printf("%d ",y[i].num);
		printf("\n");
	}
}