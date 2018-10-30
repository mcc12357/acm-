#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int a[60],n,x;
int num[50];
int b[50];
int used[50];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%d %d",&n,&x);
	int i;
	int k = 0;
	//int tmax = 0;
	int p = 0;
	int s = 0;
	int m = x;
	while(x)
	{
		if(x%2) 
		{
			b[p++] = k;
			used[k] = 1;
		}
		k++;
		x >>= 1;
	}
	for(i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		k = 0;
		int m = t;
		bool flag = false;
		while(m)
		{
			if(m%2 && !used[k])
			{
				flag = true;
				break;
			}
			k++;
			m >>= 1;
		}
		if(flag) continue;
		a[s++] = t;
		//if( (t | m) > m) continue;
		k = 0;
		while(t)
		{
			if(t%2) num[k]++;
			k++;
			t >>= 1;
		}
	}
	int res = 55;
	//printf("p=%d\n",p);
	//for(i=0;i<p;i++) printf("%d ",num[i]);
	//printf("\n");
	//for(i=0;i<p;i++) printf("%d ",b[i]);
	//printf("\n");
	for(i=0;i<p;i++) res = min(res,num[b[i]]);
	printf("%d\n",res);

}