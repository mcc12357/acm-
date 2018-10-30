#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int a[3001];
bool s[3001];
int main()
{
	int n;
	while(~scanf("%d",&n) && n != -1)
	{
		int i,j;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		memset(s,0,sizeof(s));
		int res = 0; 
		while(1)
		{
			res++;
			int k = 0;
			int temp;
			for(i=n-1;i>=0;i--) if(s[i]) {temp = a[i];break;}
			for(i=n-1;i>=0;i--)
			{
				if(s[i]) continue;
				k = 1;
				//int temp = a[i];
				s[i] = true;
				for(j=i-1;j>=0;j--)
				{
					int t = 0;
					if(a[j]>=temp) 
					{
						temp = a[j];
						s[j] = true;
						t = 1;
					}
					if(t) break;
				}
				i = j + 1;
			}
			if(k) break;
		}
		printf("%d\n",res);
	}
	return 0;
}