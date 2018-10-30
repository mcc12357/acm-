#include<iostream>
using namespace std;
int main()
{
	int f1=1,f2=1,f3,i,n;
	scanf("%d",&n);
	if(n==1||n==2) printf("1\n");
	else
	{
		for(i=3;i<=n;i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	printf("%d\n",f3);
	}
}