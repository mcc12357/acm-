#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
float f[2001][2001];
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int a[2001];
		memset(f,0,sizeof(f));
		int i,j;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			if(i>0) a[i] += a[i-1];
		}
		float res = 0.0;
		for(i=m-1;i<n;i++)//i表示区间长度,当取i个点时，区间长度为i-1
		{
			float temp = 0.0;
			for(j=0;i+j<n;j++)//j表示起点位置
			{
				int r = i + j;//r表示终点位置
				if(j>0) f[i][j] = a[r] - a[j-1];
				else f[i][j] = a[r];
				if(f[i][j]>temp) temp = f[i][j];
			}
			if(temp/(i+1)>res) res = temp/(i+1);
		}
		printf("%d\n",(int)(1000*res));
	}
	return 0;
}