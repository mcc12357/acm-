#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
vector<int> a[25];
int res[25];
int used[25];
int n;
int flag;
bool isprime(int x)
{
	int i;
	for(i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}
void dfs(int x,int p)
{
	int i;
	res[p] = x;
	used[x] = 1;
	if(p==n)
	{
		if(isprime(1+x)) 
		{
			for(i=1;i<n;i++)
			{
				printf("%d ",res[i]);	
			}
			printf("%d\n",res[n]);
			flag = 0;
		}
		return ;
	}
	int sign = 1;
	for(i=0;i<a[x].size();i++)
	{
		if(!used[a[x][i]] && a[x][i]<=n) 
		{
			sign = 0;
			used[a[x][i]] = 1;
			dfs(a[x][i],p+1);
			used[a[x][i]] = 0;
		}
	}
	used[x] = 0;
	if(sign) return ;
}

int main()
{
	int k = 1;
	int i,j;
	for(i=1;i<20;i++)
		for(j=i+1;j<20;j++)
		{
			if(isprime(i+j)) 
			{
				a[i].push_back(j);
				a[j].push_back(i);
			}
		}
	//for(i=0;i<a[7].size();i++) printf("%d ",a[5][i]);
	while(~scanf("%d",&n) && n)
	{
		printf("Case %d:\n",k);
		k++;
		if(n==1) 
		{
			printf("1\n");
			continue;
		}
		if(n%2==1)
		{
			printf("No Answer\n");
			continue;
		}
		flag = 1;
		for(i=0;i<a[1].size();i++)
		{
			if(a[1][i]>n) continue;
			memset(used,0,sizeof(used));
			memset(res,0,sizeof(res));
			res[1] = 1;
			used[1] = 1;
			dfs(a[1][i],2);
		}
		if(flag) printf("No Answer\n");
	}
	return 0;
}