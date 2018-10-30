#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 100010
int a[maxn],num1[maxn],num2[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
	}
	if(a[0]==1) num1[0] = 1;
	if(a[0]==2) num2[0] = 1;
	for(i=1;i<n;i++) 
	{
		if(a[i]==1) num1[i] = num1[i-1] + 1;
		else num1[i] = num1[i-1];
		if(a[i]==2) num2[i] = num2[i-1] + 1;
		else num2[i] = num2[i-1];
	}
	long long res = 0;
	for(i=0;i<n-1;i++)
	{
		if(a[i]==1) res += num1[n-1] - num1[i] + n - 1 - i;
		else if(a[i]==2) res += num1[n-1] - num1[i] + num2[n-1] - num2[i];
		else res += num1[n-1] - num1[i];
	}
	printf("%lld\n",res);
}