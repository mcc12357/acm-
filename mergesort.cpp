#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1000
int count = 0;
void mergesort(int a[],int l,int r)
{
	count++;
	if(r<=l) return ;
	int mid = (l + r) / 2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
	int b[maxn];
	int p = l,q = mid + 1,k = l;
	while(k<=r)
	{
		if(a[p]<a[q]&&p<=mid || q>r)
		{
			b[k] = a[p];
			p++;
		}
		else
		{
			b[k] = a[q];
			q++;
		}
		k++;
	}
	int i;
	for(i=l;i<=r;i++) a[i] = b[i];

}
int main()
{
	int a[maxn],n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
	printf("%d\n",count);
}