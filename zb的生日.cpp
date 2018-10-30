#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>	
int n,w[21],av,res[21];
int dfs(int x)
{
	if(res[x]) return res[x];
	if(x==n-1) return res[x]; 
	if(fabs(dfs(x+1) - av)<fabs(dfs(x+1) + w[x] - av)) return dfs(x+1);
	else return dfs(x+1) + w[x];
}
int main()
{

	while(scanf("%d",&n)!=EOF)
	{
		int i,j,sum = 0;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&w[i]);
			sum += w[i];
		}
		av = sum / 2;
		memset(res,0,sizeof(res));
		printf("%d\n",dfs(n-1));
		

	}
	return 0;
}