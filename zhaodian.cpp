//±àµÄ²»¶Ô
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int m;
	int a[202];
	while(scanf("%d",&m)!=EOF)
	{
		memset(a,-1,sizeof(a));
		int left,right;
		scanf("%d %d",&a[0],&a[1]);
		int p = m-1;
		int j = 2;
		while(p--)
		{
			scanf("%d %d",&left,&right);
			int i;
			int k = 0;
			for(i=0;a[i]!=-1;)
			{
				if(left>=a[i]&&right<=a[i+1]) {a[i] = left;a[i+1] = right;k=1;}
				if(left<=a[i]&&right<=a[i+1]&&right>=a[i]) {a[i+1] = right;k=1;}
				if(left>=a[i]&&right>=a[i+1]&&left<=a[i+1]) {a[i] = left;k=1;}
				if(left<=a[i]&&right>=a[i+1]) k=1;
				i+=2;
			}
			if(k==0) 
			{
				a[j] = left;
				a[j+1] = right;
				j+=2;
			}
		}
		int x;
		for(x=0;;x++) 
		{
			if(a[x]==-1) break;
			//printf("%d\n",a[x]);
		}
		printf("%d\n",x/2);

		return 0;
	}
}