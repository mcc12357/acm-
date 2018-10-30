#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>		
int f[1001][1001];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[1001],b[1001];
		scanf("%s",a);
		int len = strlen(a);
		int i,j;
		for(i=0;i<len;i++) b[i] = a[len-i];
		memset(f,0,sizeof(0));
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				if(a[i]==b[j]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = max(f[i][j-1],f[i-1][j]);
			}
		}
		printf("%d\n",len - f[len-1][len-1]);
	}
	return 0;
}