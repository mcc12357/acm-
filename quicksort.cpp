#include<iostream>
using namespace std;
void print (int a[],int n)
{
	for(int j=0;j<n;j++)
	{
		cout<<a[j]<<" ";
	}
	cout<<endl;
}

void swap(int *a,int *b)
{
	int tmp=*a;
	*a = *b;
	*b=tmp;
}
int partition(int a[],int low,int high)
{
	int privotkey = a[low];
	while(low<high)
	{
		while(low<high && a[high] >= privotkey) --high;
		swap(&a[low],&a[high]);
		while(low<high && a[low] <= privotkey) ++low;
		swap(&a[low],&a[high]);
	}

}
int main()
{

}