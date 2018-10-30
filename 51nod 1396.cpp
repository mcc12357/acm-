#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define maxn 1000010
char a[maxn];
int n0[maxn],n1[maxn];
int main()
{
	scanf("%s",a);
	int n = strlen(a);
	int i;
	n0[0] = 0;
	for(i=1;i<=n;i++)
	{
		if(a[i-1]=='0')
		{
			n0[i] = n0[i-1] + 1;
		}
		else n0[i] = n0[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		if(a[i]=='1') n1[i] = n1[i+1] + 1;
		else n1[i] = n1[i+1];
	}
	bool flag = false;
	int k;
	for(i=0;i<=n;i++)
	{
		if(n0[i]==n1[i])
		{
			flag = true;
			k = i;
			break;
		}
	}
	if(flag) printf("%d\n",k);
	else 
	{
		printf("-1\n");
	}
}