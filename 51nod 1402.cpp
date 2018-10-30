#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
int pos[100],a[100];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int i,j;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&pos[i],&a[i]);
		}
		pos[0] = 1;
		a[0] = 0;
		m++;
		pos[m] = n;
		a[m] = n - 1;
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=m;j++)
			{
				if(i==j) continue;
				if( fabs(pos[i]-pos[j]) < fabs(a[i]-a[j]))
				{
					if(a[i]<a[j])
					{
						a[j] = a[i] + fabs(pos[i]-pos[j]);
					}
					else
					{
						a[i] = a[j] + fabs(pos[i]-pos[j]);
					}
				}
			}
		}
		int ans = 0;
		for(i=1;i<=m;i++)
		{
			if(fabs(a[i]-a[i-1]) <= pos[i]-pos[i-1])
			{
				int tm = max(a[i],a[i-1]);
				ans = max(ans, tm + (pos[i] - (pos[i-1] + fabs(a[i]-a[i-1])) ) / 2 ); 
			}
			else
			{
				ans = max(a[i],a[i-1]);
			}
		}
		printf("%d\n",ans);
	}
}