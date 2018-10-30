#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<queue>
struct Time
{
	int l,r;
}time[10010];
priority_queue<int,vector<int>,greater<int> > q;
bool cmp(Time x,Time y)
{
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) scanf("%d %d",&time[i].l,&time[i].r);
	sort(time,time+n,cmp);
	int res = 0;
	for(i=0;i<n;i++)
	{
		if(q.empty()) 
		{
			res++;
			q.push(time[i].r);
			continue;
		}
		int x = q.top();
		if(time[i].l>=x) 
		{
			q.pop();
			q.push(time[i].r);
		}
		else
		{
			res++;
			q.push(time[i].r);
		}
	}
	printf("%d\n",res);
}