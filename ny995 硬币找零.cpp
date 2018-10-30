#include<iostream>
using namespace std;
#include<stdio.h>
#define INF 1e9
int a[55],res[100005];
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int main()
{
	int n,k;
	while(~scanf("%d %d",&n,&k) && (n+k))
	{
		int i,j;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<=100000;i++) res[i] = INF;
		res[0] = 0;
		//printf("%d\n",res[1]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<=k && j+a[i]<=k;j++)
			{
				if(res[j]==INF) continue;
				res[j+a[i]] = min(res[j+a[i]],res[j] + 1);
			}
		}
		for(i=k;i>=0;i--) if(res[i]!=INF) break;
		printf("%d\n",res[i]);
	}
	return 0;

}