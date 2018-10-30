#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int const INF = -100000001; 
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,sum = INF,a[1000001],res[1000001];
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++) 
		{
			res[i] = INF;
			scanf("%d",&a[i]);
		}
		int len;
		int k = 0;
		for(i=0;i<n;i++)
		{
			if(i>=1) k += a[i-1];
			if(k>0) continue;
			int temp = 0;
			for(len=1;len+i<n;len++)
			{
				temp = temp + a[i+len-1];
				res[i] = max(temp,res[i]);
			}
			sum = max(sum,res[i]);
		}
		printf("%d\n",sum);
	}
}