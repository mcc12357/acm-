#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
struct Circle
{
	int l,r;
}circle[50010];
int n;
bool cmp(Circle x,Circle y)
{
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int heart,R;
		scanf("%d %d",&heart,&R);
		circle[i].l = heart - R;
		circle[i].r = heart + R;
	}
	sort(circle,circle+n,cmp);
	int res = 0;
	for(i=1;i<n;i++)
	{
		int l = 0,r = i - 1;
		while(r - l > 1)
		{
			int mid = (l + r) / 2;
			if(circle[mid].r>=circle[i].l) r = mid;
			else l = mid;
		}
		int tm;
		if(circle[r].r<circle[i].l) tm = r;
		else if(circle[l].r<circle[i].l) tm = l;
		else tm = -1;
		res += tm + 1;
	}
	printf("%d\n",res);
}