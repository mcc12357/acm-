#include<iostream>
using namespace std;
#include<stdio.h>
int ans[30];
int main()
{
	int k;
	long long res[15];
	res[0] = 1;
	for(k=1;k<=14;k++)
	{
		long long i,j;
		int n = 2 * k;
		for(i=res[k-1];;i++)
		{
			ans[0] = 0;
			for(j=1;j<=k;j++)
			{
				ans[j] = (ans[j-1] + i - 1) % (n-j+1);
				if(ans[j]<k) break;
			}
			if(j==k+1 && ans[k]>=k) break;
		}
		res[k] = i;
		//printf("%lld\n",i);
		//for(i=0;i<=k;i++) printf("%I64d\n",ans[i]);
	}
	while(~scanf("%d",&k) && k)
	{
		printf("%lld\n",res[k]);
	}
}