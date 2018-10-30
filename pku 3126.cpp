#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
struct path
{
	int x;
	int num;
};
int m,n;
int res;
bool flag;
int visited[10005];
bool isprime[10005];
queue<path> que;
void init(int n)
{
	int i,j;
	for(i=0;i<=n;i++) isprime[i] = true;
	isprime[0] = isprime[1] = false;
	for(i=2;i<=n;i++)
	{
		if(isprime[i])
		{
			for(j=2*i;j<=n;j+=i) isprime[j] = false;
		}
	}
}
void f(path tm)
{
	int t;
	int i,j;
	int k = 1;
	for(i=1;i<=4;i++)
	{
		t = tm.x - (tm.x/k)%10 * k;
		for(j=0;j<=9;j++)
		{
			if(i==4 && j==0) {t += k;continue;}
			if(t==n)
			{
				res = tm.num + 1;
				flag = true;
				return ;
			}
			if(isprime[t] && !visited[t]) 
			{
				path p;
				p.x = t;
				p.num = tm.num+1;
				que.push(p);
				visited[t] = 1;
			}
			t += k;
		}
		k *= 10;
	}

}
int main()
{
	int t;
	scanf("%d",&t);
	init(10000);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		flag = false;
		memset(visited,0,sizeof(visited));
		res = -1;
		while(!que.empty()) que.pop();
		path tm;
		tm.x = m;
		tm.num = 0;
		que.push(tm);
		visited[m] = 1;
		while(!que.empty())
		{
			tm = que.front();
			if(tm.x==n)
			{
				res = tm.num;
				break;
			}
			f(tm);
			if(flag) break;
			que.pop();
		}
		if(res!=-1) printf("%d\n",res);
		else printf("Impossible\n");
	}
}