#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
char a[1000010];
int main()
{
	while(~scanf("%s",a))
	{
		int m = strlen(a);
		if(m%2) printf("NO\n");
		else
		{
			int n = m / 2;
			int i;
			bool flag = true;
			for(i=0;i<n;i++)
			{
				if(a[i]!=a[i+n])
				{
					flag = false;
					break;
				}
			}
			if(flag) printf("YES\n");
			else printf("NO\n");
		}
	}
}
