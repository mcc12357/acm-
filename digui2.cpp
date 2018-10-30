#include<iostream>
#include<algorithm>
using namespace std;
void invert(int *a,int m,int n)
{
	if(n<2||m>n) return;
	else
	{
		swap(a[m-1],a[n-1]);
		invert(a,m+1,n-1);
	}
}
int main()
{
	int a[5]={1,2,3,4,5};
	invert(a,2,5);
	for(int i=0;i<5;i++) printf("%d ",a[i]);
	cout<<endl;
}