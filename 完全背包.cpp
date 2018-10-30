#include<iostream>
using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int m,n,i,j,res;//m表示容量，n表示次数
	int a[100],b[100],f[20000];
	memset(f,0,sizeof(f));
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
	for(i=0;i<n;i++)
	{
		for(j=a[i];j<=m;j++) f[j]=max(f[j],f[j-a[i]]+b[i]);
	}
	res = f[0];
	for(i=0;i<=m;i++) if(f[i]>res) res = f[i];
	printf("%d\n",res);
}