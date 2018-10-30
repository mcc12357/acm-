#include<iostream>
using namespace std;
int gcm(int m,int n)
{
	if(n==0) return m;
	else{
		gcm(n,m%n);
	}
}
int main()
{
	printf("%d\n",gcm(3,15));
}