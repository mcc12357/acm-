#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int res[100001],a[1001];
int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int n,sum = 0;
		scanf("%d",&n);
		int i,j;
		memset(res,0,sizeof(res));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		res[0] = 1;
		for(i=0;i<n;i++)
		{
			sum += a[i];
			for(j=sum;j>=0;j--)
			{
				if(j==a[i]) continue;
				if(res[j]) res[j+a[i]] = 1;
			}
		}
		int av = sum / 2;
		for(i=av;i>=0;i--)
		{
			if(res[i]) break;
		}
		printf("%d\n",sum - 2 * i);
		
	}
}