#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,n,i,j,k=0,q=1;
	char a[500+1][2000+1];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%s",&a[i]);
		for(i=n-1;i>0;i--)
		{
			k=0;
			for(j=0;j<=i-1;j++)
			{
				char *p;
				p=strstr(a[i],a[j]);
				if(!p) {k=1;break;}
			}
			if(k==1) break;
		}

		if(k) printf("Case #%d: %d\n",q,i+1);
		else printf("Case #%d: -1\n",q);
		q++;

	}
}