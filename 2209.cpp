#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	char a[20];
	while(scanf("%s",a)!=EOF)
	{
		int m;
		char *p = a;
		m = strlen(a);
		for(int i=0;i<m;i++) a[i] = a[i] - '0';
		int sum = 0;
		for(;p<a+m;p++) sum += *p;
		if(sum%2) printf("NO\n");
		else if(sum==0) printf("0\n");
		else
		{
			p = a;
			int res = 0;
			char *start = p;
			while(p<a+m)
			{
				p++;
				if(*p==1)
				{
					p = start;
					while(p<a+m && *p==0)
					{
						p++;
					}
					*p = 0;
					p++;
					res++;
					while(p<a+m && *p==0)
					{
						p++;
						res++;
					}
					*p = 0;
				}
				
			}
			printf("%d\n",res);
		}
	}
}