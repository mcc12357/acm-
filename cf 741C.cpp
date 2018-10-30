#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 110000
int a[maxn],b[maxn];
int res[maxn*2],f[maxn*2];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%d %d",&a[i],&b[i]);
		f[a[i]] = b[i];
		f[b[i]] = a[i];
	}
	for(i=1;i<=2*n;i++)
	{
		int cur = i;
		int nxt = i;
		while(res[cur]==0)
		{
			res[cur] = 1;
			if(cur%2) nxt = cur + 1;
			else nxt = cur - 1;
			if(nxt==2*n+1) nxt = 1;
			res[nxt] = 2;
			cur = f[nxt];
		}
	}
	for(i=1;i<=n;i++) printf("%d %d\n",res[a[i]],res[b[i]]);
}