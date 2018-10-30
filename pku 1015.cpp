#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
int n,m;
int dp[21][801];
int path[21][801];
int p[801],d[801],s[801],v[801];
bool select(int j,int k,int i)
{
	while(j>0 && path[j][k]!=i)
	{
		k -= v[path[j][k]];
		j--;
	}
	if(j>0) return false;
	return true;
}
int main()
{
	int time = 1;
	while(~scanf("%d %d",&n,&m) && (m||n))
	{
		int i,j,k;
		memset(dp,-1,sizeof(dp));
		memset(path,0,sizeof(path));
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&p[i],&d[i]);
			s[i] = p[i] + d[i];
			v[i] = p[i] - d[i];
		}
		int fix = m * 20;
		dp[0][fix] = 0;
		for(j=1;j<=m;j++)
		{
			for(k=0;k<=2*fix;k++)
			{
				if(dp[j-1][k]>=0)
				{
					for(i=1;i<=n;i++)
					{
						if(k+v[i]>=0 && k+v[i]<=2*fix && dp[j][k+v[i]]<dp[j-1][k]+s[i])
						{
							if(select(j-1,k,i))
							{
								dp[j][k+v[i]] = dp[j-1][k] + s[i];
								path[j][k+v[i]] = i;
							}
						}
					}
				}
			}
		}
		for(k=0;k<=fix;k++)
		{
			if(dp[m][fix-k]>=0 || dp[m][fix+k]>=0) break;
		}
		int div = dp[m][fix-k] > dp[m][fix+k] ? (fix-k) : (fix+k);
		cout<<"Jury #"<<time++<<endl;
		cout<<"Best jury has value ";
		cout<<(dp[m][div]+div-fix)/2<<" for prosecution and value ";
		cout<<(dp[m][div]-div+fix)/2<<" for defence:"<<endl;
		int id[21];
		i = 0;
		k = div;
		for(j=m;j>=1;j--)
		{
			id[i++] = path[j][k];
			k -= v[path[j][k]];
		}
		sort(id,id+m);
		for(i=0;i<m;i++)  
            cout<<' '<<id[i];  
        cout<<endl<<endl;
	}
}