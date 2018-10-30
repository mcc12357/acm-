#include<iostream>
using namespace std;
#include<algorithm>
int a[10] = {2,5,34,23,6,7,12,4,2,45};
bool bsearch(int x,int low,int high)
{
	if(low>high) return false;
	int mid = (low + high) / 2;
	if(a[mid]==x) return true;
	if(x<a[mid]) bsearch(x,low,mid-1);
	else bsearch(x,mid+1,high);
}
int main()
{
	sort(a,a+10);
	int m;
	scanf("%d",&m);
	if(bsearch(m,0,9)) printf("yes\n");
	else printf("no\n");
}