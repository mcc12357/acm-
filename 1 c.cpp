#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
struct Tower
{
	int x,y,z;
}tower[300];
int dp[300];
int k;
void f(int x,int y,int z)
{
	tower[k].x = x;
	tower[k].y = y;
	tower[k].z = z;
	k++;
}
bool cmp(Tower a,Tower b)
{
	if(a.x==b.x && a.y==b.y) return a.z<b.z;
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	int n;
	int cnt = 1;
	while(~scanf("%d",&n) && n)
	{
		int i,j;
		k = 0;
		int x,y,z;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			f(x,y,z);
			f(x,z,y);
			f(y,x,z);
			f(y,z,x);
			f(z,x,y);
			f(z,y,x);
		}
		sort(tower,tower+k,cmp);
		for(i=0;i<k;i++) dp[i] = tower[i].z;
		int ans = 0;
		for(i=0;i<k;i++)
		{
			for(j=0;j<i;j++)
			{
				if(tower[i].x>tower[j].x && tower[i].y>tower[j].y) dp[i] = max(dp[i],dp[j]+tower[i].z);	
			}
			ans = max(ans,dp[i]);
		}
		printf("Case %d: maximum height = %d\n",cnt,ans);
		cnt++;
	}
}