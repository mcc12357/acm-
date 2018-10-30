#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
struct Work
{
	int index,deadline,day;
	char name[105];
}work[20];
bool cmp(Work a,Work b)
{
	if(a.deadline==b.deadline) return a.index<b.index;
	return a.deadline<b.deadline;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%s %d %d",work[i].name,&work[i].deadline,&work[i].day);
			work[i].index = i;
		}
		sort(work,work+n,cmp);
		int sum = 0,total = 0;
		for(i=0;i<n;i++)
		{
			sum += work[i].day;
			if(sum>work[i].deadline) total += sum - work[i].deadline;
		}
		printf("%d\n",total);
		for(i=0;i<n;i++) printf("%s\n",work[i].name);
	}
}
