#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<3)
		{
			printf("%d\n",n);
			continue;
		}
		if(n%2)
		{
			printf("%lld\n",(long long)(n-1)*(n-2)*(n));
		}
		else
		{
			if(n%3==0)
			{
				printf("%lld\n",(long long)(n-1)*(n-2)*(n-3));//不用long long转变类型会哇
			}
			else
				printf("%lld\n",(long long)(n)*(n-1)*(n-3));
		}
	}
}