#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
const int inf = 1000000005;
struct Cow
{
	int weight;
	int strength;
	int id;
}cow[50005];
int wsum[50005];
bool cmp(Cow x,Cow y)
{
	if(x.strength==y.strength) return x.weight>y.weight;
	return x.strength<y.strength;
}
int n;
struct cap
{
	int val;
	int id;
};
bool operator < (const cap &x,const cap &y)
{
	return x.val<y.val;
}
priority_queue<cap> que;
bool f(int k)
{
	int i;
	while(!que.empty()) que.pop();
	cap tm;
	tm.id = 1;
	tm.val = cow[1].strength + cow[1].weight;
	que.push(tm);
	for(i=2;i<=n;i++)
	{
		if(cow[i].strength+k>=wsum[i-1])
		{
			tm.id = i;
			tm.val = cow[i].strength + cow[i].weight;
			que.push(tm);
		}
		else
		{
			tm = que.top();
			if(tm.val+k<wsum[i]) return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d %d",&cow[i].weight,&cow[i].strength);
	if(n==1) printf("%d\n",-cow[1].strength);
	else
	{
		sort(cow+1,cow+n+1,cmp);
		for(i=1;i<=n;i++) cow[i].id = i;
		memset(wsum,0,sizeof(wsum));
		wsum[0] = 0;
		for(i=1;i<=n;i++) wsum[i] = wsum[i-1] + cow[i].weight;
		int lb = -inf,ub = inf;
		while(ub - lb > 1)
		{
			int mid = (lb + ub) / 2;
			if(f(mid)) ub = mid;
			else lb = mid;
		}
		if(f(lb)) printf("%d\n",lb);
		else printf("%d\n",ub);
	}
}
