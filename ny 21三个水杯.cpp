#include<iostream>
using namespace std;
#include<queue>
#include<stdio.h>
#include<string.h>
int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
struct s
{
	int s1,s2,s3,step;
};
int v1,v2,v3,t1,t2,t3;
int visited[101][101][101];
queue<s> que;
int bfs(s b)
{
	que.push(b);
	while(!que.empty())
	{
		s c = que.front();
		que.pop();
		if(c.s1==t1 && c.s2==t2 && c.s3==t3) return c.step;
		s a;
		if(c.s1 && c.s3!=v3) 
		{
			a = c;
			int temp = a.s1;
			a.s1 -= min(v3-a.s3,a.s1);
			a.s3 += min(v3-a.s3,temp);
			a.step++;
			if(!visited[a.s1][a.s2][a.s3]) que.push(a);
			visited[a.s1][a.s2][a.s3] = 1;
		}
		if(c.s1 && c.s2!=v2)
		{
			a = c;
			int temp = a.s1;
			a.s1 -= min(v2-a.s2,a.s1); 
			a.s2 += min(v2-a.s2,temp);
			a.step++;
			if(!visited[a.s1][a.s2][a.s3]) que.push(a);
			visited[a.s1][a.s2][a.s3] = 1;
		}
		if(c.s2 && c.s1!=v1)
		{
			a = c;
			int temp = a.s2;
			a.s2 -= min(v1-a.s1,a.s2);
			a.s1 += min(v1-a.s1,temp);
			a.step++;
			if(!visited[a.s1][a.s2][a.s3]) que.push(a);
			visited[a.s1][a.s2][a.s3] = 1;
		}
		if(c.s2 && c.s3!=v3)
		{
			a = c;
			int temp = a.s2;
			a.s2 -= min(v3-a.s3,a.s2);
			a.s3 += min(v3-a.s3,temp);
			a.step++;
			if(!visited[a.s1][a.s2][a.s3]) que.push(a);
			visited[a.s1][a.s2][a.s3] = 1;
		}
		if(c.s3 && c.s1!=v1)
		{
			a = c;
			int temp = a.s3;
			a.s3 -= min(v1-a.s1,a.s3);
			a.s1 += min(v1-a.s1,temp);
			a.step++;
			if(!visited[a.s1][a.s2][a.s3]) que.push(a);
			visited[a.s1][a.s2][a.s3] = 1;
		}
		if(c.s3 && c.s2!=v2)
		{
			a = c;
			int temp = a.s3;
			a.s3 -= min(v2-a.s2,a.s3);
			a.s2 += min(v2-a.s2,temp);
			a.step++;
			if(!visited[a.s1][a.s2][a.s3]) que.push(a);
			visited[a.s1][a.s2][a.s3] = 1;
		}
	}
	return -1;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		s a;
		while(!que.empty()) que.pop();//记得每做完一次队列要清空
		scanf("%d %d %d %d %d %d",&v1,&v2,&v3,&t1,&t2,&t3);
		a.s1 = v1;
		a.s2 = 0;
		a.s3 = 0;
		a.step  = 0;
		memset(visited,0,sizeof(visited));
		printf("%d\n",bfs(a));
	}
}