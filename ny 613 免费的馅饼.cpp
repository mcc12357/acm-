//³¬Ê±
#include<iostream>
using namespace std;
#include<algorithm>
#include<stdio.h>
#include<string.h>
int res[100005][15];
struct npie
{
	int point;
	int time;
};
bool cmp(npie x,npie y)
{
	if(x.time==y.time) return x.point < y.point;
	return x.time < y.time;
}
int max3(int x,int y,int z)
{
	if(x>=y && y>=z) return x;
	if(y>=x && y>=z) return y;
	if(z>=x && z>=y) return z;
}
int max2(int x,int y)
{
	if(x>=y) return x;
	else return y;
}
int main()
{
	int n,i;
	while(scanf("%d",&n) && n)
	{
		npie pie[100001];
		memset(res,0,sizeof(res));
		for(i=0;i<n;i++) scanf("%d %d",&pie[i].point,&pie[i].time);
		sort(pie,pie+n,cmp);
		int t,pos = 5;
		for(t=0;t<=pie[n-1].time;t++)
		{
			int temp;
			for(i=-1;i<=1;i++)
			{
				temp = pos + i;
				if(temp < 0 && temp >10) continue;
				int k,sign = 1;
				for(k=0;k<n;k++)
				{
					if(pie[k].time>t+1) break;
					if(temp==pie[k].point && t+1==pie[k].time) 
					{
						res[temp][t+1] = max2( max2(res[temp-1][t],res[temp][t]),max2(res[temp+1][t],res[temp][t+1]) ) +1;
						sign = 0;
					}
				}
				if(sign) res[temp][t+1] = max3(res[temp-1][t],res[temp][t],res[temp+1][t]);
			}
			pos = temp;
		}
		int kk = res[0][pie[n-1].time+1];
		for(i=0;i<=10;i++) if(res[i][pie[n-1].time+1]>kk) kk = res[i][pie[n-1].time+1];
		printf("%d\n",kk);

		
	}
}