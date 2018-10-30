#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double sum = 0;
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)
		{
			sum += log10(i);
		}
		sum++;
		int res = (int)sum;
		printf("%d\n",res);
	}
	return 0;
}