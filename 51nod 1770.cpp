#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	int t,a,b,d,n;
	scanf("%d",&t);
	FILE *fp;
	fp = fopen("C:\\11.txt","w");
	while(t--)
	{
		scanf("%d %d %d %d",&a,&b,&d,&n);
		if(a*b<10)
		{
			if(a*b==d) 
			{
				printf("%d\n",n);
				fprintf(fp,"%d\n",n);
			}
			else 
			{
				printf("0\n");
				fprintf(fp,"0\n");
			}
		}
		else
		{
			int ans = 0;
			int l = a * b % 10,r = a * b / 10;
			if(l==d) ans++;
			int u = 0;
			int k;
			while(1)
			{
				k = a * b + r;
				if(k%10==l) break;
				l = k % 10;
				r = k / 10;
				if(l==d) ans++;
				u++;
			}
			
			if(k%10==d) ans += n - u - 1;
			if((a*b+r)/10==d) ans++;
			printf("%d\n",ans);
			fprintf(fp,"%d\n",ans);
		}
	}
}