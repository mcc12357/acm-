#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
typedef _int64 ll;
int n;
int res[5];
int a[1010];
bool used[1010];
bool flag = false;
void dfs(int x,int i)
{
	res[x] = i;
	used[i] = 1;
	if(x==1)
	{
		ll tm = 0 - a[res[0]] - a[res[1]];
		int l = 0,r = n - 1;
		while(r-l>1)
		{
			int mid = (l + r) / 2;
			if(a[mid]<tm) l = mid;
			else r = mid;
		}
		if(a[r]==tm && !used[r] && r>res[1])
		{
			printf("%d %d %d\n",a[res[0]],a[res[1]],a[r]);
			flag = true;
			return ;
		}
		else if(a[l]==tm && !used[l] && l>res[1])
		{
			printf("%d %d %d\n",a[res[0]],a[res[1]],a[l]);
			flag = true;
			return ;
		}
		used[res[1]] = 0;
		return ;
	}
	int j;
	for(j=i+1;j<n;j++) dfs(x+1,j);
	used[i] = 0;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	memset(used,0,sizeof(used));
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		dfs(0,i);
	}
	if(!flag) printf("No Solution\n");
}
