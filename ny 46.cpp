#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int sum = 0,m,n;
		scanf("%d",&m);
		int i = 0;
		n = m;
		while(m)
		{
			m = (m >> 1);
			i++;
		}
		i--;
		sum += i;
		m = n - (1 << i);
		//if(m==1) sum++;
		//printf("%d\n",m);
		while(m)
		{
			if((m & 1)==1) sum++;
			m = (m >> 1);
		}
		printf("%d\n",sum);
	}
}