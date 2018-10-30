#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<cmath>
int a[12];
int res[12];
int visited[12];
int num;
int k;
int l,r;
int ans;
void dfs(int now,int val)
{
	int i;
	if(now==num+1)
	{
		int t1 = 0,t2 = 0;
		for(i=1;i<=k-1;i++)
		{
			t1 = t1 * 10 + res[i];
		}
		for(i=k;i<=num;i++)
		{
			t2 = t2 * 10 + res[i];
		}
		if(fabs(t1-t2)<ans) ans = fabs(t1-t2);
		return ;
	}
	if(now<=k && l==-1 && r!=-1 && visited[r]) return ;
	if(now<=k && l!=-1 && r==-1 && visited[l]) return;
	if(now<=k && l!=-1 && r!=-1 && visited[r] && visited[l]) return ;
	if(now==k+1 && val==0) return;
	if(now==k)
	{
		if(l!=-1 && !visited[l])
		{
			visited[l] = 1;
			res[k] = a[l];
			dfs(now+1,a[l]);
			visited[l] = 0;
		}
		if(r!=-1 && !visited[r])
		{
			visited[r] = 1;
			res[k] = a[r];
			dfs(now+1,a[r]);
			visited[r] = 0;
		}
	}
	else
	{
		for(i=1;i<=num;i++)
		{
			if(!visited[i])
			{
				res[now] = a[i];
				visited[i] = 1;
				dfs(now+1,a[i]);
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		int i;
		int p = 1;
		ans = 1000000;
		char ch;
        while((ch=getchar())!='\n')
        {
            if(ch==' ')
               continue;
            a[p++]=ch-'0';
        }
		num = p - 1;
		k = num / 2 + 1;
		//printf("%d %d\n",k,num);
		if(num%2==0)
		{
			//printf("%d\n",num);
			memset(visited,0,sizeof(visited));
			memset(res,0,sizeof(res));
			for(i=1;i<=num;i++)
			{
				l = r = -1;
				if(a[i])
				{
					visited[i] = 1;
					if(i>1) l = i-1;
					if(i<num) r = i+1;
					res[1] = a[i];
					dfs(2,a[i]);
					memset(visited,0,sizeof(visited));
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			if(a[1]==0)
			{
				res[2] = 0;
				res[1] = a[2];
				for(i=3;i<=k;i++) res[i] = a[i];
				for(i=k+1;i<=num;i++) res[i] = a[num-i+k+1];
			}
			else
			{
				for(i=1;i<=k;i++) res[i] = a[i];
				for(i=k+1;i<=num;i++) res[i] = a[num-i+k+1];
			}
			int t1 = 0,t2 = 0;
			for(i=1;i<=k;i++)
			{
				t1 = t1 * 10 + res[i];
			}
			for(i=k+1;i<=num;i++)
			{
				t2 = t2 * 10 + res[i];
			}
			ans = t1 - t2;
			printf("%d\n",ans);
		}
	}
}