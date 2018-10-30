#include<iostream>
using namespace std;
int main()
{
	int m,n,a[101],i,j;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(m==0 && n==0) break;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) if(a[i]<=m && a[i+1]>=m) break;
		for(j=0;j<=i;j++) printf("%d ",a[j]);
		printf("%d ",m);
		for(j=i+1;j<n-1;j++) printf("%d ",a[j]);
		printf("%d\n",a[n-1]);
		
	}
}