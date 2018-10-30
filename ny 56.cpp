#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
int f[10005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		f[0] = 0;
		f[1] = 0;
		int i;
		int n,m;
		scanf("%d %d",&n,&m);
		for(i=2;i<=n;i++)
		{
			f[i] = f[i-1];
			int temp = i;
			while(temp%m==0 && temp>=m)
			{
				f[i]++;
				temp /= m;
			}
		}
		printf("%d\n",f[n]);
	}
	return 0;
}