#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	int m,n,k,t,i;
	char a[35];
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		//memset(a,0,sizeof(a));
		if(m>=0)
		{
			k=0;
			while(m)
			{
				t=m%n;
				if(t>=10) a[k++]=t-10+'A';
				else a[k++]=t+'0';
				m/=n;
			}
			for(i=k-1;i>=0;i--) printf("%c",a[i]);
			printf("\n");
		}

		if(m<0)
		{
			m=-m;
			k=0;
			while(m)
			{
				t=m%n;
				if(t>=10) a[k++]=t-10+'A';
				else a[k++]=t+'0';
				m/=n;
			}
			cout<<'-';
			for(i=k-1;i>=0;i--) printf("%c",a[i]);
			printf("\n");
		}
	}
}