#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
struct Jewel
{
	int num,v,w;
	double y;
}jewel[100010];
int n,k;
const double eps = 0.001; 
bool cmp(Jewel a,Jewel b)
{
	return a.y>b.y;
}
int main()
{
	while(~scanf("%d %d",&n,&k))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&jewel[i].v,&jewel[i].w);
			jewel[i].num = i + 1;
		}
		double p = 0.0,res = 0.5;
		while(fabs(res-p)>=eps)
		{
			p = res;
			for(i=0;i<n;i++)
			{
				jewel[i].y = jewel[i].v - res * jewel[i].w;
			}
			sort(jewel,jewel+n,cmp);
			double sv = 0,sw = 0;
			for(i=0;i<k;i++)
			{
				sv += jewel[i].v;
				sw += jewel[i].w;
			}
			res = sv / sw;
		}
		for(i=0;i<k-1;i++) printf("%d ",jewel[i].num);
		printf("%d\n",jewel[k-1].num);
	}
}