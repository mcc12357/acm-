//此代码超时
#include<iostream>
using namespace std;
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF && t)
	{
		int a[200000],i,j,res;
		for(i=0;i<t;i++) scanf("%d",&a[i]);
		res = a[0];
		for(i=1;i<t;i++) res = res ^ a[i];//^为异或
		if(res==0) printf("No\n");
		else
		{
			printf("Yes\n");
			for(i=0;i<t;i++)
			{
				if(i==0)
				{
					res = a[1];
					for(j=2;j<t;j++) res = res ^ a[j];
					if(a[0]>res) printf("%d %d\n",a[0],res);
				}
				else
				{
					res = a[0];
					for(j=1;j<t;j++)
					{
						if(j==i) continue;
						res = res ^ a[j];

					}
					if(a[i]>=res) printf("%d %d\n",a[i],res);
				}
			}
		}
	}
}