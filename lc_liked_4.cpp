#include<iostream>
using namespace std;
#include<stdio.h>
int max(int x,int y)
{
    if(x>y) return x;
    return y;
}
int min(int x,int y)
{
    if(x<y) return x;
    return y;
}
double find(int* a, int m, int* b, int n)
{
    int i,j;
    int l = 0,r = m;//寻找合适的划分位置
    while(1)
    {
        int mid = (l + r) / 2;
        i = mid;
        j = (m + n - 2 * i) / 2;
        if((i==0 || j==n || a[i-1]<=b[j]) && (j==0 || i==m || b[j-1]<=a[i])) break;
        else if(i==0 || j==n || a[i-1]<=b[j]) l = mid + 1;
        else r = mid - 1;
    }
    if((m+n)%2) 
    {
        if(i==m) return b[j];
        if(j==n) return a[i];
        return min(a[i],b[j]);
    }
    else
    {
        if(i==0 && j==n) return (a[0]+b[n-1]) / 2.0;
		if(i==0) return (b[j-1]+min(a[0],b[j])) / 2.0;
        if(j==0 && i==m) return (a[m-1]+b[0]) / 2.0;
		if(j==0) return (a[i-1]+min(a[i],b[j])) / 2.0;
        if(i==m) return (max(a[m-1],b[j-1])+b[j]) / 2.0;
        if(j==n) return (a[i]+max(a[i-1],b[n-1])) / 2.0;
        return (max(a[i-1],b[j-1]) + min(a[i],b[j])) / 2.0;
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double res;
    if(nums1Size<=nums2Size) res = find(nums1,nums1Size,nums2,nums2Size);
    else res = find(nums2,nums2Size,nums1,nums1Size);
    return res;
}
int main()
{
	int nums1[4] = {2,3,4,5};
	int nums2[1] = {1};
	double res = findMedianSortedArrays(nums1,4,nums2,1);
	printf("%.1f\n",res);
}