#include<iostream>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		int i,j,a=1,a1=0,a2=0,a3=0;
		for(i=2;i<=n;i++)
		{
			a+=a3;
			a3=a2;
			a2=a1;
			a1=a;
		}
		a=a+a1+a2+a3;
		printf("%d\n",a);

	}
}