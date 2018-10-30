#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#define maxn 51000
struct Inter
{
	int l,r,c;
}inter[maxn];
int n;
bool cmp(Inter x,Inter y)
{
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int bit[maxn];
bool used[maxn];
int sum(int i)
{
	int s = 0;
	while(i>0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=50000)
	{
		bit[i] += x;
		i += i & -i;
	}
}
int main()
{
	scanf("%d",&n);
	int i;
	memset(bit,0,sizeof(bit));
	int res = 0;
	for(i=1;i<=n;i++) scanf("%d %d %d",&inter[i].l,&inter[i].r,&inter[i].c);
	sort(inter+1,inter+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		int a = inter[i].l;
		int b = inter[i].r;
		int tm = sum(b) - sum(a-1);
		int k = inter[i].c;
		if(k>tm)
		{
			int j;
			k -= tm;
			for(j=b;k;j--)
			{
				if(!used[j])
				{
					add(j,1);
					used[j] = 1;
					res++;
					k--;
				}
			}
		}
	}
	//add(3,1000);
	//printf("%d\n",sum(10));
	printf("%d\n",res);

}