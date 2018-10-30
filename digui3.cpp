#include<iostream>
using namespace std;
void print(int n)
{
	if(n==0) return;
	else
	{
		print(n-1);
		for(int i=0;i<n;i++)
		{
			cout<<n<<' ';
		}
		cout<<endl;
	}
}
int main()
{
	print(5);
}