#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
struct Stick
{
	int l,w;
}stick[5010];
bool used[5010];
bool cmp(Stick x,Stick y)
{
	if(x.l==y.l) return x.w<y.w;
	return x.l<y.l;
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
			scanf("%d %d",&stick[i].l,&stick[i].w);
		}
		memset(used,0,sizeof(used));
		sort(stick,stick+n,cmp);
		int res = 0;
		while(1)
		{
			
			int k = 0;
			while(used[k]) {used[k] = 1;k++;}
			if(k==n) break;
			used[k] = 1;
			res++;
			for(i=k+1;i<n;i++)
			{
				if(!used[i] && stick[i].l>=stick[k].l && stick[i].w>=stick[k].w)
				{
					used[i] = 1;
					k = i;
				}
			}
		}
		printf("%d\n",res);

	}
}