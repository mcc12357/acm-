#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	int t,m;
	scanf("%d",&t);
	char a[101];
	while(t--)
	{
		cin >> a;
		//scanf("%s",a);
		scanf("%d",&m);
		int i,j,k;
		int length = strlen(a);
		char temp = a[0];
		int	sign = 0;
		for(i=0;i<length;i++)
		{
			if(m==0) break;
			temp = a[i];
			sign = i;
			for(j=i;j<=i+m;j++)
			{			
				/*k = 0;
				if(a[j]=='9')
				{
					temp = a[j];
					sign = j;
					k = 1;
				}
				if(k = 1) break;*/
				if(a[j]>temp) 
				{
					temp = a[j];
					sign = j;
				}
				
			}
			printf("%c",a[sign]);
			m -= (sign - i);
			i = sign;
		}
		//for(;i<length;i++) printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}