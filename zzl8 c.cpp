#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
struct point
{
	int x,step;
};
queue<point> q;
bool used[100010];
const int inf = 100000;
int main()
{
	int s,t;
	while(~scanf("%d %d",&s,&t))
	{
		while(!q.empty()) q.pop();
		memset(used,0,sizeof(used));
		point S;
		S.x = s;
		S.step = 0;
		q.push(S);
		used[s] = true;
		int ans = 0;
		while(!q.empty())
		{
			point cur = q.front();
			q.pop();
			if(cur.x==t)
			{
				ans = cur.step;
				break;
			}
			point in;
			if(cur.x-1>=0 && !used[cur.x-1])
			{
				in.x = cur.x - 1;
				in.step = cur.step + 1;
				used[in.x] = true;
				q.push(in);
			}
			if(cur.x+1<=inf && !used[cur.x+1])
			{
				in.x = cur.x + 1;
				in.step = cur.step + 1;
				used[in.x] = true;
				q.push(in);
			}
			if(2*cur.x<=inf && !used[2*cur.x])
			{
				in.x = 2 * cur.x;
				in.step = cur.step + 1;
				used[in.x] = true;
				q.push(in);
			}
		}
		printf("%d\n",ans);
	}
}