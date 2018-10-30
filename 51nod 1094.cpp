#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 10010
typedef _int64 ll;
int a[maxn];
ll sum[maxn];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int i;
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		if(i==0) sum[i] = a[i];
		else sum[i] = sum[i-1] + a[i];
	}
	int j;
	bool flag = false;
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n-1;j++)
		{
			if(i==0)
			{
				if(sum[j]==k)
				{
					flag = true;
					break;
				}
			}
			else
			{
				if(sum[j]-sum[i-1]==k)
				{
					flag = true;
					break;
				}
			}
		}
		if(flag) break;
	}
	if(flag) printf("%d %d\n",i+1,j+1);
	else printf("No Solution\n");
}