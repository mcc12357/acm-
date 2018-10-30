#include<iostream>
using namespace std;
int sum(int *a,int n)
{
	//int result;
	if(n==1) return a[n-1];
	else
	{
		return sum(a,n-1)+a[n-1];
	}
}
int main()
{
	int a[5]={1,2,3,4,5};
	printf("%d\n",sum(a,5));
}