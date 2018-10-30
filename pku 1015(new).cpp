#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<cmath>
#include<algorithm>
int n,m;
int v[205],p[205];
int dp[25][805];
int path[25][805];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
/*bool select(int k,int j,int i)
{
	while(j>0 && path[j][k]!=i)
	{
		k-=v[path[j][k]];  
        j--; 
	}
	return j?false:true;
}*/
int main()
{
	int time = 1;
	while(~scanf("%d %d",&n,&m) && (m||n))
	{
		int a[205],b[205];
		int i,j,k;
		for(i=1;i<=n;i++) 
		{
			scanf("%d %d",&a[i],&b[i]);
			p[i] = a[i] + b[i];
			v[i] = a[i] - b[i];
		}
		int fix = m * 20;
		
		for(i=0;i<=m;i++) 
			for(j=0;j<=2*fix;j++) dp[i][j] = -1;
		dp[0][fix] = 0;
		memset(path,-1,sizeof(path));
		path[0][fix] = 0;
		int tr = 0,res[25];
		for(i=1;i<=n;i++)
		{
			int flag = 0;
			for(j=m;j>=1;j--)
			{
				if(v[i]>0)
				{
					for(k=2*fix;k>=0;k--)
					{
						if(j>=1 && k-v[i]>=0 && k-v[i]<=2*fix && dp[j-1][k-v[i]]>=0)
						{
							if(dp[j-1][k-v[i]]+p[i]>dp[j][k])
							{
								dp[j][k] = dp[j-1][k-v[i]]+p[i];
								path[j][k] = i;
							}
						}
					}
				}
				else if(v[i]<0)
				{
					for(k=0;k<=2*fix;k++)
					{
						if(j>=1 && k-v[i]>=0 && k-v[i]<=2*fix && dp[j-1][k-v[i]]>=0)
						{
							if(dp[j-1][k-v[i]]+p[i]>dp[j][k])
							{
								dp[j][k] = dp[j-1][k-v[i]]+p[i];
								path[j][k] = i;
							}
						}
					}
				}
				else
				{
					res[tr] = i;
					tr++;
					flag = 1;
					break;
				}
				if(flag) break;
			}

		}
		int ula;
		for(i=0;i<=fix;i++)
		{
			if(dp[m][fix+i]>=0 || dp[m][fix-i]>=0)
			{
				break;
			}
		}
		ula = dp[m][fix+i]>dp[m][fix-i] ? (fix+i) : (fix-i);
		printf("%d %d\n",dp[m][fix+i],dp[m][fix-i]);
		int tmp = m;
		while(tmp>=1)
		{
			res[tr] = path[tmp][ula];
			tr++;
			ula -= v[path[tmp][ula]];
			tmp--;
		}
		sort(res,res+tr);
		int tm1 = 0,tm2 = 0;
		for(i=0;i<tr;i++) 
		{
			tm1 += a[res[i]];
			tm2 += b[res[i]];
		}
		printf("Jury #%d\n",time);
		time++;
		printf("Best jury has value %d for prosecution and value %d for defence:\n",tm1,tm2);
		for(i=0;i<m;i++)
		{
			printf(" %d",res[i]);
		}
		printf("\n\n");
		//printf("%d %d\n",i,ula);
	}
}
/*
4 2
1 2
2 3
4 1
6 2

8 4    
19 18
 5  9
 0  9
 5  0
 4  4
16  9
 4 15
20  5

  7 4    
19 18
 5  9
 0  9
 5  0
16  9
 4 15
20  5
*/