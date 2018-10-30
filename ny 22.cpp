#include<iostream>
using namespace std;
#include<math.h>
#include<stdio.h>
bool judge(int k)
{
	int i;
	if(k<=1) return false;
	for(i=2;i<=sqrt(k);i++)
	{
		if(k%i==0) return false;
	}
	return true;
}
int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int n;
		scanf("%d",&n);
		int i,k;
		int sum = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			if(judge(k)) sum += k;
		}
		printf("%d\n",sum);
	}
	return 0;
}