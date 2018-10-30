#include<iostream>
using namespace std;
void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void insertsort(int a[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		j=i-1;
		x=a[i];
		if(a[i]<a[i-1])
		{
			//j=i-1;
			//x=a[i];
			a[i]=a[i-1];
			while(x<a[j])
			{
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=x;
		}
		else a[j+1]=x;
	}
}
int main()
{
	int a[8]={9,2,3,5,9,6,7,8};
	insertsort(a,8);
	print(a,8);
}