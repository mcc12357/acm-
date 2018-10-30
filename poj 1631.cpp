#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#define maxn 40010
int a[maxn];
const int inf = maxn;
int n;
int dp[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<=n;i++) dp[i] = inf;
		for(i=0;i<n;i++)
		{
			int l = 0,r = n - 1;
			while(r-l>1)
			{
				int mid = (l + r) / 2;
				if(a[i]<dp[mid]) r = mid;
				else l = mid;
			}
			if(dp[l]>a[i]) dp[l] = a[i];
			else if(dp[r]>a[i]) dp[r] = a[i];
		}
		for(i=0;i<n;i++) if(dp[i]==inf) break;
		printf("%d\n",i);

	}
}