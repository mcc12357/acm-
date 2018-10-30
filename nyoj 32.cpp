#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int m,n;
int res[15];
int used[15];
void dfs(int t,int x)
{
	int i,j;
	if(t==n)
	{
		for(i=0;i<n;i++) printf("%d",res[i]);
		printf("\n");
		return ;
	}
	for(i=x;i>=1;i--)
	{
		if(!used[i]) {res[t] = i;used[i] = 1;}
		dfs(t+1,i-1);
		used[i] = 0;
	}

}
void dfs()
{
	
}
int main()
{
	//int m,n;
	scanf("%d %d",&m,&n);
	dfs(0,m);
	
}