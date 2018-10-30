#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 55
int n,w;
int a[maxn],ans[maxn];
int mmin = 10000;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
void dfs(int x,int cur,int num,int sum)
{
	ans[x] = a[cur];
	num++;
	sum += a[cur];
	int i;
	if(sum>w) return ;
	if(sum==w)
	{
		for(i=0;i<x;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[x]);
		return;
	}
	for(i=cur+1;i<n;i++)
	{
		if(w-sum>=a[i]) dfs(x+1,i,num,sum);
	}
	num--;
	sum -= a[cur];

}
int main()
{
	scanf("%d %d",&n,&w);
	int i;
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		mmin = min(mmin,a[i]);
	}
	memset(ans,0,sizeof(ans));
	for(i=0;i<n;i++) if(a[i]<=w) dfs(0,i,0,0);

}