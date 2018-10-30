#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int n,sum;
int visited[15];
int res[15];
int a[15][15] = {{0},{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,10,10,5,1},
{1,6,15,20,15,6,1},{1,7,21,35,35,21,7,1},{1,8,28,56,70,56,28,8,1},{1,9,36,84,126,126,84,36,9,1}};
bool flag = false;
/*void init()
{
	a[1] = {1};
	a[2] = {1,1};
	a[3] = {1,2,1};
	a[4] = {1,3,3,1};
	a[5] = {1,4,6,4,1};
	a[6] = {1,5,10,10,5,1};
	a[7] = {1,6,15,20,15,6,1};
	a[8] = {1,7,21,35,35,21,7,1};
	a[9] = {1,8,28,56,70,56,28,8,1};
	a[10] = {1,9,36,84,126,126,84,36,9,1};
}*/
void dfs(int x,int k)
{
	int i;
	res[x] = k;
	if(x==n)
	{
		int ans = 0;
		for(i=1;i<=n;i++) ans += res[i] * a[n][i-1];
		if(ans==sum)
		{
			flag = true;
		}
		return ;
	}
	if(flag) return ;
	for(i=1;i<=n;i++)
	{
		if(flag) return ;
		if(!visited[i])
		{
			visited[i] = 1;
			dfs(x+1,i);
			visited[i] = 0;
		}
	}
}
int main()
{
	//init();
	scanf("%d %d",&n,&sum);
	dfs(0,0);
	int i;
	for(i=1;i<n;i++) printf("%d ",res[i]);
	printf("%d\n",res[n]);
}