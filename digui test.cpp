#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int a,b,c;
int res[10000];
void dfs(int x,int y,int z)//x为当前待放入的位置，y为待放入的数，z为剩下多少需要求和
{
	res[x] = y;
	z -= y;
	int i;
	if(z>y && z<=b)
	{
		for(i=0;i<=x;i++)
		{
			printf("%d ",res[i]);
		}
		printf("%d\n",z);
	}
	if(z<=y) return ;
	for(i=y+1;i<=b;i++)
	{
		dfs(x+1,i,z);
	}

}
int main()
{
	while(~scanf("%d %d %d",&a,&b,&c))
	{
		int i;
		for(i=a;i<=b;i++)
		{
			dfs(0,i,c);
		}
	}
}