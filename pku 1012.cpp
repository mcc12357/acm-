//简单模拟，但是算到10就非常慢了，最好用公式计算
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int k;
int used[1500000];
bool f(int x)
{
	int i = 1;
	int index = 0;
	int s = 2 * k;
	int t = 0;
	while(index<k)
	{
		if(!used[i] && t==x)
		{
			if(i<=k) return false;
			used[i] = 1;
			index++;
			t = 0;
		}
		while(t<x)
		{
			if(i<s)
			{
				if(!used[i])
				{
					t++;
					if(t==x) break;
				}
				i++;
			}
			if(i==s)
			{
				if(!used[i])
				{
					t++;
					if(t==x) break;
				}
				i = 1;
			}
		}
	}
	return true;
}
int main()
{
	while(~scanf("%d",&k) && k)
	{
		int i;
		for(i=k+1;;i++)
		{
			memset(used,0,sizeof(used));
			if(f(i)) break;
		}
		printf("%d\n",i);
	}
}