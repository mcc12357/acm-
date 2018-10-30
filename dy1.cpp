#include<iostream>
int fmax(int m,int n)
{
	if(m>=n) return m;
	else return n;
}
using namespace std;
int main()
{
	int t,i,j,max;
	scanf("%d",&t);
	int a[100],f[100];
	for(i=0;i<t;i++) scanf("%d",&a[i]);
	f[0] = a[0];
	for(i=1;i<t;i++)
	{
		if(f[i-1]>0 && a[i]>0) f[i] = f[i-1] + a[i];
		else f[i] = fmax(a[i],f[i-1]);
	}
	printf("%d\n",f[t-1]);
}