#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
typedef _int64 ll;
struct Cow
{
	int point;
	int need;
}cow[100005];
int n,m;
ll total;
/*bool operator < (const Cow &x,const Cow &y)
{
	return x.need < y.need;
}*/
bool cmp(Cow x,Cow y)
{
	return x.point<y.point;
}
priority_queue<int> que1;
priority_queue<int> que2;
int low[100005],up[100005];
int main()
{
	scanf("%d %d %I64d",&n,&m,&total);
	int i;
	while(!que1.empty()) que1.pop();
	while(!que2.empty()) que2.pop();
	for(i=1;i<=m;i++) scanf("%d %d",&cow[i].point,&cow[i].need);
	sort(cow+1,cow+1+m,cmp);
	ll left = 0,right = 0;
	memset(low,0,sizeof(low));
	memset(up,0,sizeof(up));
	for(i=1;i<=n/2;i++)
	{
		que1.push(cow[i].need);
		left += cow[i].need;
		que2.push(cow[m-i+1].need);
		right += cow[i].need;
	}
	low[n/2] = left;
	up[m-n/2+1] = right;
	for(i=n/2+1;i<=m-n/2+1;i++)
	{
		int j = m - i + 2;
		int tm = que1.top();
		if(cow[i].need<tm)
		{
			left = left + cow[i].need - tm;
			que1.pop();
			que1.push(cow[i].need);
		}
		low[i] = left;
		tm = que2.top();
		if(cow[j].need<tm)
		{
			right = right + cow[j].need - tm;
			que2.pop();
			que2.push(cow[j].need);
		}
	}
	int res = -1;
	for(i=m-n/2+1;i>=n/2+1;i--)
	{
		if(low[i-1]+up[i-1]+cow[i].need<=total)
		{
			res = i;
			break;
		}
	}
	if(res!=-1)
	{
		printf("%d\n",cow[res].point);
	}
	else
	{
		printf("-1\n");
	}
}
/*
3 5 70
30 25
50 21
20 20
5 18
35 30
*/