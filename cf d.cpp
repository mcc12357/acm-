#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int m,n;
int day[100005],need[100005];
int passsed[100005];
int front[100005];
bool f(int k)
{
	int i;
	memset(passed,0,sizeof(passed));
	int res = k;
	for(i=k;i>=1;i--)
	{
		if(day[i] && !passed[day[i]])
		{
			
		}
	}
}
int main()
{
	while(~scanf("%d %d",&m,&n))
	{
		int i;
		for(i=1;i<=m;i++) scanf("%d",&day[i]);
		for(i=1;i<=n;i++) scanf("%d",&need[i]);
		for(i=m;i>=2;i--)
		{

		}
		int left = 1,right = m;
		if(f(right))
		{
			while(right-left>=0)
			{
				int mid = (left+right) / 2;
				if(f(mid))
				{
					right = mid;
				}
				else
				{
					left = mid;
				}
			}
		}
		else
		{
			printf("-1\n");
		}
	}
}