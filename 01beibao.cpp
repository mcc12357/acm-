#include<iostream>
using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int m,n,a[100],b[100],f[100],i,j;//a[]为重量，b[]为价值
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
	for(i=0;i<m;i++) f[i]=0;
	for(i=0;i<m;i++)
	{
		for(j=n;j>=a[i];j--)
		{
			f[j]=max(f[j],f[j-a[i]]+b[i]);
		}
	}
	int res=f[0];
	for(i=0;i<n;i++) if(res<f[i]) res = f[i];
	printf("%d\n",res);

}