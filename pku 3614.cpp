#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<queue>
struct Lotion
{
	int rate;
	int num;
}lotion[2505];
struct Cow
{
	int smin;
	int smax;
}cow[2505];
bool cmp1(Cow x,Cow y)
{
	if(x.smin==y.smin) return x.smax<y.smax;
	return x.smin<y.smin;
}
bool cmp2(Lotion x,Lotion y)
{
	return x.rate<y.rate;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int i;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&cow[i].smin,&cow[i].smax);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&lotion[i].rate,&lotion[i].num);
	}
	sort(cow,cow+m,cmp1);
	sort(lotion,lotion+n,cmp2);
	//printf("%d %d\n",cow[0].smin,cow[0].smax);
	priority_queue<int,vector<int>,greater<int> > que;
	while(!que.empty()) que.pop();
	int j = 0;
	int res = 0;
	for(i=0;i<n;i++)
	{
		while(lotion[i].rate>=cow[j].smin && j<m && lotion[i].num>0)
		{
			que.push(cow[j].smax);
			j++;
		}
		while(!que.empty())
		{
			int tm = que.top();
			if(tm>=lotion[i].rate)
			{
				lotion[i].num--;
				res++;
				que.pop();
				if(lotion[i].num==0) break;
			}
			if(tm<lotion[i].rate)
			{
				que.pop();
			}
		}
		if(j>=m && que.empty()) break;
	}
	printf("%d\n",res);

}