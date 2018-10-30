#include<iostream>
using namespace std;
#include<stdio.h>
bool isprime[10005];
int visited[10005];
int a,b;
int res;
const int inf = 1e6;
bool judge(int x,int y)
{
	int i= 0;
	while(x)
	{
		if(x%10==y%10) i++;
		x /= 10;
		y /= 10;
	}
	if(i==3) return true;
	return false;
}
void dfs(int x,int step)
{
	visited[x] = 1;
	if(x==b)
	{
		res = step;
		return ;
	}
	if(step>res) return;
	int i; 
	for(i=1000;i<10000;i++)
	{
		if(isprime[i] && !visited[i] && judge(x,i)) 
		{
			visited[i] = 1;
			dfs(i,step+1);
			visited[i] = 0;
		}
	}
}
int main()
{
	int p = 0;
	int i,j;
	for(i=0;i<10000;i++) isprime[i] = true;
	isprime[0] = isprime[1] = false;
	for(i=2;i<10000;i++)
	{
		if(isprime[i])
		{
			p++;
			for(j=2*i;j<10000;j+=i) isprime[j] = false;
		}
	}
	//printf("%d\n",p);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(visited,0,sizeof(visited));
		res = inf;
		scanf("%d %d",&a,&b);
		dfs(a,0);
		if(res==inf) printf("Impossible\n");
		else printf("%d\n",res);
	}
	return 0;
} 