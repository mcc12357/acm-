#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
typedef _int64 ll;
ll dp[2][100005];
ll sum[100005];
const int mod = 1000000;
int up[10005];
int ant[1005];
int m,n,l,r;
int main()
{
	scanf("%d %d %d %d",&m,&n,&l,&r);
	int i,tm,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tm);
		ant[tm]++;
	}
	for(i=1;i<=m;i++) up[i] = up[i-1] + ant[i];
	dp[0][0] = 1;
	//for(i=0;i<=ant[1];i++) dp[0][i] = 1;
	ll *prv = dp[0],*nxt = dp[1];
	for(i=1;i<=m;i++)	
	{
		memset(sum,0,sizeof(sum));
		sum[0] = 1;
		for(j=1;j<=up[i];j++)
		{
			sum[j] = (sum[j-1] + prv[j]) % mod;
		}
		for(j=0;j<=up[i];j++)
		{
			if(j<=ant[i]) nxt[j] = sum[j];
			else 
			{
				nxt[j] = (sum[j] - sum[j-ant[i]-1]) % mod;
			}
		}
		swap(prv,nxt);
	}
	ll ans = 0;
	for(i=l;i<=r;i++) ans = (ans + prv[i]) % mod;
	printf("%d\n",(ans+mod)%mod);
}