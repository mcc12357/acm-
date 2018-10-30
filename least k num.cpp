#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1000
void quicksort(int a[],int l,int r,int k)
{
	int i = l,j;
	for(j=l+1;j<=r;j++)
	{
		if(a[j]<=a[l] && i+1<=r)
		{
			swap(a[j],a[i+1]);
			i++;
		}
	}
	swap(a[l],a[i]);
	if(i-l+1==k || i-l+1==k-1) return ;
	else if(i-l+1>k) quicksort(a,l,i-1,k);
	else quicksort(a,i+1,r,k-i-l-1);
}
int main()
{
	int a[maxn];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	int k;
	scanf("%d",&k);
	quicksort(a,0,n-1,k);
	for(i=0;i<k;i++) printf("%d ",a[i]);
	printf("\n");
}