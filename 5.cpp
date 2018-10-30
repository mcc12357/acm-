#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<cstring>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n,i,j,k,r,y,q,a[100],b[100],c[100],d[100],e[100];
		scanf("%d %d",&m,&n);
		for(i=0;i<m;i++) scanf("%d",&a[i]);
		k=0;
		y=0;
		for(i=0;i<m;i++) 
		{
			if(a[i]>m) y=1;
		}
		if(y) {printf("hzh\n");continue;}
		memset(c,0,sizeof(c));
		for(i=0;i<m;i++)
			for(j=i+1;j<m;j++) if(a[j]==a[i]&&c[j]==0&&c[i]==0)
			{
				b[k++]=a[j];
				c[j]=1;
				c[i]=1;
			}
		r=0;
		for(i=1;i<=m;i++)
		{
			for(j=0;j<m;j++) 
			{
				if(a[j]==i) break;
			}
			if(j==m) c[r++]=i;
		}
		for(i=0;i<k;i++) {d[i]=b[i]%n;e[i]=c[i]%n;}
		sort(d,d+k);
		sort(e,e+k);
		for(i=0;i<k;i++) if(d[i]!=e[i]) break;
		if(i<k) {printf("hzh\n");y=1}
		if(y) continue;
		if(i==k) 
		{
			memset(d,0,sizeof(d));
			memset(e,0,sizeof(e));
			sort(b,b+k);
			sort(c,c+k);
			for(j=0;j<k;j++)
			{
				for(q=0;q<k&&b[j]==0&&c[q]==0;q++)
				{
					if()
				}
			}
		}
	}
	return 0;
}