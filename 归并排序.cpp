/*
*  归并排序是将两个(或两个以上)有序表合并成一个新的有序表，即把待排序序列分为
*  若干个子序列，每个子序列是有序的，然后再把有序的子序列合并为整体有序序列
*  归并排序是分治算法的一个典型的应用，而且是稳定的一种排序，这题利用归并排序
*  的过程中，计算每个小区间的逆序数，进而得到大区间的逆序数。那么，问题就解决了。
*
*/
#include <stdio.h>

#define max 1000001

long long a[max],b[max];
long long count;
void Merge(long long a[], int start, int mid , int end)  //归并排序的合并部分 
{
	int i = start,j = mid + 1,k = start;
	while(i <= mid&&j <= end)
	{
		if(a[i] <= a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			count += j - k;
			b[k++] = a[j++];
		}
	}
	while(i <= mid)
	{
		b[k++] = a[i++];
	}
	while(j <= end)
	{
		b[k++] = a[j++];
	}
	for(int i = start; i <= end; i++)
	{
		a[i] = b[i];
	}
}

void MergeSort(long long a[], int start, int end)  //归并排序 
{
	if(start < end)
	{
		int mid = (start + end)/2;
		MergeSort(a,start,mid);     // 将前半部分排序 
		MergeSort(a,mid+1,end);     // 将后半部分排序 
		Merge(a,start,mid,end);     // 合并前后两个部分 
	}
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		count = 0;
		for(int i = 0; i < m; i++)
		{
			scanf("%d",a+i);
		}
		MergeSort(a,0,m-1);
		printf("%lld\n",count);
	}
	return 0;
}