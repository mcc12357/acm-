#include<iostream>
using namespace std;
int main()
{
	int a[100],f[20000];
	int m,n,i,j;
	memset(f,0,sizeof(f));
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	f[0]=1;
	for(i=0;i<n;i++)
		for(j=m;j>=a[i];j--)
		{
			if(!f[j]) f[j] = f[j-a[i]];
		}
		for(i=m;i>=0;i--) if(f[i]) {printf("%d\n",m-i);break;}
}