#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
struct interval
{
	int left;
	int right;
}time[25005];
bool cmp(interval x,interval y)
{
	if(x.left==y.left) return x.right>y.right;
	return x.left<y.left;
}
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int n,t;
int main()
{
	scanf("%d %d",&n,&t);
	int i;
	for(i=1;i<=n;i++) scanf("%d %d",&time[i].left,&time[i].right);
	sort(time+1,time+n+1,cmp);
	if(time[1].left!=1) printf("-1\n");
	else
	{
		int k = time[1].right;
		int count = 1;
		i = 2;
		int tmp;
		int flag = 1;
		while(i<=n && k<t)
		{
			k++;
			tmp = 0;
			for(;i<=n;i++)
			{
				if(time[i].left>k) break;
				tmp = max(tmp,time[i].right);
			}
			if(tmp<=k-1)
			{
				flag = 0;
				break;
			}
			k = tmp;
			count++;
		}
		if(k>=t && flag) printf("%d\n",count);
		else printf("-1\n");
	}
}
/*
7 10
1 7
2 3
1 4
3 8
3 6
6 9
9 10
*/