#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
typedef _int64 ll;
int n;
int k = 0;
int num[20];
ll f1(int x)
{
	int i;
	ll res = 0;
	for(i=0;i<x;i++)
	{
		res = res * 10 + num[i];
	}
	return res;
}
ll f2(int x)
{
	int i;
	ll res = 0;
	for(i=x+1;i<k;i++)
	{
		res = res * 10 + num[i];
	}
	return res;
}
int f3(int x)
{
	int i;
	int res = 1;
	for(i=x;i<k-1;i++) 
	{
		res *= 10;
	}
	return res;
}
ll f(int j)
{
	ll left = f1(j);
	ll right = f2(j);
	if(num[j]>1)
	{
		return (left+1) * f3(j);
	}
	else if(num[j]==1)
	{
		return left * f3(j) + right + 1; 
	}
	else 
	{
		return left * f3(j);
	}
}
int main()
{
	scanf("%d",&n);
	int x = n;
	while(x)
	{
		num[k++] = x % 10;
		x /= 10;
	}
	reverse(num,num+k);
	int i;
	//for(i=0;i<k;i++) printf("%d",num[i]);
	ll ans = 0;
	for(i=0;i<k;i++)
	{
		ans += f(i);
	}
	printf("%I64d\n",ans);
}