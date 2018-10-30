#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
float a[15];
int used[15];
int target,n;
bool flag;
float res;
float abs(float x)
{
	if(x>0) return x;
	return -x;
}
void dfs(int top,int num)//top为新得到的数在数组中的位置，num为当前数组中的个数
{
	if(num==1)
	{
		if(abs(res-target)<0.0001) flag = 1;
		return ;
	}
	int i,j;
	for(i=0;i<top-1;i++)
	{
		if(used[i]) continue;
		used[i] = 1;
		for(j=i+1;j<top;j++)
		{
			if(used[j]) continue;
			used[j] = 1;
			res = a[i] + a[j];
			a[top] = res;
			dfs(top+1,num-1);
			if(flag) return ;
			res = a[i] - a[j];
			a[top] = res;
			dfs(top+1,num-1);
			if(flag) return;
			res = a[j] - a[i];
			a[top] = res;
			dfs(top+1,num-1);
			if(flag) return;
			res = a[i] * a[j];
			a[top] = res;
			dfs(top+1,num-1);
			if(flag) return;
			if(a[i])
			{
				res = a[j] / a[i];
				a[top] = res;
				dfs(top+1,num-1);
				if(flag) return;
			}
			if(a[j])
			{
				res = a[i] / a[j];
				a[top] = res;
				dfs(top+1,num-1);
				if(flag) return ;
			}
			used[j] = 0;
		}
		used[i] = 0;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		flag = false;
		memset(used,0,sizeof(used));
		scanf("%d %d",&n,&target);
		if(n==0)
		{
			if(target==0) printf("Yes\n");
			else printf("No\n");
			continue;
		}
		int i;
		for(i=0;i<n;i++) scanf("%f",&a[i]);
		if(n==1)
		{
			if(a[0]==target) printf("Yes\n");
			else printf("No\n");
			continue;
		}
		dfs(n,n);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}