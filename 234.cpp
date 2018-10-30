#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
int m,n;
int l[100005],r[100005];
int res;
int ans[100005];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	scanf("%d %d",&n,&m);
	int i;
	res = n;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&l[i],&r[i]);
		res = min(res,r[i] - l[i] + 1);
	}
	for(i=0;i<n;i++)
		ans[i] = i % res;
	printf("%d\n",res);
	for(i=0;i<n-1;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n-1]);
}