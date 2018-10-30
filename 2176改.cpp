#include<iostream>
using namespace std;
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF && t)
	{
		int a[200000],i,j,res,temp;
		for(i=0;i<t;i++) scanf("%d",&a[i]);
		res = a[0];
		for(i=1;i<t;i++) res = res ^ (a[i]);//^ÎªÒì»ò
		if(res==0) printf("No\n");
		else
		{
			printf("Yes\n");
			for(i=0;i<t;i++)
			{
				temp = res ^ a[i];
				if(a[i]>temp) printf("%d %d\n",a[i],temp);
			}


		}
	}
}