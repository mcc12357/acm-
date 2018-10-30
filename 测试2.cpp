#include<iostream>
using namespace std;
int main()
{
	int i;
	char *a[10];
	for(i=0;i<2;i++)
		cin>>*(a[i]);
	for(i=0;i<2;i++)
		cout<<*(a[i])<<endl;
}