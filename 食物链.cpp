#include<iostream>
using namespace std;
int n,k;
int pre[500];
int find(int x)
{
	int r = x;
	while(pre[r]!=r)
	{
		r = pre[r];
	}
	int i = x,j;
	while(pre[i]!=r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
bool same(int x,int y)
{
	if(find(x)==find(y)) return true;
	return false;
}
void unite(int x,int y)
{
	if(find(x)!=find(y))
		pre[find(y)] = find(x);
}
int main()
{
	int x,y,t;
	scanf("%d %d",&n,&k);//n个动物，k条信息
	int i;
	for(i=0;i<3*n;i++)
	{
		pre[i] = i;
	}
	int ans = 0;
	for(i=0;i<k;i++)
	{
		scanf("%d %d %d",&t,&x,&y);
		
		x -= 1;
		y -= 1;//把输入变成0,1，……n-1范围
		if(x<0 || x>=n || y<0 || y>=n) 
		{
			ans++;
			continue;
		}
		if(t==1)
		{
			if(same(x,y+n) || same(x,y+2 * n)) ans++;
			else 
			{
				unite(x,y);
				unite(x+n,y+n);
				unite(x+2*n,y+2*n);
			}
		}
		else
		{
			if(same(x,y) || same(x,y+2*n)) ans++;
			else
			{
				unite(x,y+n);
				unite(x+n,y+2*n);
				unite(x+2*n,y);
			}
		}
	}
	printf("%d\n",ans);
}
