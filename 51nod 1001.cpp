#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
int k,n;
int a[50010];
bool flag = false;
int main()
{
	scanf("%d %d",&k,&n);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		int l = 0,r = n - 1;
		while(r-l>1)
		{
			int mid = (l + r) / 2;
			if(a[mid]<k-a[i]) l = mid;
			else r = mid;
		}
		if(l>i && a[l]==k-a[i])
		{
			printf("%d %d\n",a[i],a[l]);
			flag = true;
		}
		else if(r>i && a[r]==k-a[i])
		{
			printf("%d %d\n",a[i],a[r]);
			flag = true;
		}
	}
	if(!flag) printf("No Solution\n");
}