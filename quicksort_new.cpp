#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#define maxn 1000
int rangenum(int s,int t)
{
	 srand((unsigned int)time(NULL));
	 int x = s + rand()%(t-s+1);
	 return x;
}
void quicksort(int a[],int s,int t)
{
	if(t<=s) return ;
	int index = rangenum(s,t);
	swap(a[s],a[index]);
	int i=s,j;
	for(j=s+1;j<=t;j++)
	{
		if(a[j]<=a[s])
		{
			if(i+1>=s && i+1<=t) swap(a[i+1],a[j]);
			i++;
		}
	}
	swap(a[s],a[i]);
	quicksort(a,s,i-1);
	quicksort(a,i+1,t);

}
int main()
{
	int a[maxn];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}