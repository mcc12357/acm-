#include<iostream>
using namespace std;
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF && t)
	{
		int i,f1=0,f2=2,m=2;
		for(i=3;i<=t;i++)
		{
			f1 = f2;
			m *= 2;
			f2 = (m - f1)%10000;
			m = (m % 10000 + 10000);
		}
		if(t==1) printf("%d\n",f1);
		else printf("%d\n",f2);
	}
}