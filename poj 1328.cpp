#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<math.h>
int n,r;
struct interval
{
	double left;
	double right;
}iter[1005];
bool cmp(interval x,interval y)
{
	return x.left<y.left;
}
double min(double x,double y)
{
	if((x-y)<1e-6) return x;
	return y;
}
int main()
{
	int t = 1;
	while(~scanf("%d %d",&n,&r) && (n||r))
	{
		int i;
		int a[1005],b[1005];
		int flag = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
			if(b[i]>r) flag = 1;
		}
		if(flag) printf("Case %d: -1\n",t);
		else
		{
			for(i=1;i<=n;i++)
			{
				iter[i].left = a[i] - sqrt( 1.0 * (r*r - b[i]*b[i]) );
				iter[i].right = a[i] + sqrt( 1.0 * (r*r - b[i]*b[i]) );
			}
			sort(iter+1,iter+n+1,cmp);
			double ll = iter[1].left,rr = iter[1].right;
			int count = 1;
			for(i=2;i<=n;i++)
			{
				if(iter[i].left<=rr)
				{
					ll = iter[i].left;
					rr = min(rr,iter[i].right);
				}
				else
				{
					ll = iter[i].left;
					rr = iter[i].right;
					count++;
				}
			}
			printf("Case %d: %d\n",t,count);
		}
		t++;
	}
}