#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
int n;
int a[55];
bool flag;
bool used[55],vis[1000010];
void dfs(int d,int x,int b[])
{
	if(flag) return ;
	int i,j;
	if(x==d-1) 
	{
		//memset(vis,0,sizeof(vis));
		if(used[a[n-1]]) return ;
		b[x] = a[n-1];
		x++;
		for(i=0;i<n;i++) vis[a[i]] = false;
		//int sum[10];
		//sum[0] = b[0];
		//for(i=1;i<x;i++) sum[i] = sum[i-1] + b[i];
		for(i=0;i<x;i++)
		{
			for(j=i+1;j<x;j++)
			{
				vis[(int)fabs(b[i]-b[j])] = true;
			}
		}
		for(i=0;i<n;i++) if(!vis[a[i]]) return ;
		flag = true;
		return ;
	}
	for(i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i] = true;
			b[x] = a[i];
			dfs(d,x+1,b);
			used[i] = false;
		}
	}
	
}
int main()
{
	while(~scanf("%d",&n) && n)
	{
		int i;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		n = unique(a,a+n) - a;
		sort(a,a+n);
		int b[55];
		b[0] = 0;
		flag = false;
		for(i=2;i<=7;i++)
		{
			memset(used,0,sizeof(used));
			dfs(i,1,b);
			if(flag) break;
		}
		printf("%d\n",i);
	}
}