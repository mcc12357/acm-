#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
const int inf = 200000;
int res[5][5][100005];
int result[100005];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
struct num
{
	int sec;
	int third;
	int val;
	int pace;
};
void turn(int x,int a[])
{
	int i;
	for(i=4;i>=0;i--)
	{
		a[i] = x % 10;
		x /= 10;
	}
}
int change(int b[])
{
	int i;
	int x = 0;
	for(i=0;i<5;i++) x = x * 10 + b[i];
	return x;
} 
queue<num> que;
void bfs(int now)
{
	num tm;
	tm.val = now;
	tm.sec = 3;
	tm.third = 2;
	tm.pace = 0;
	que.push(tm);
	int i,j;
	while(!que.empty())
	{
		tm = que.front();
		que.pop();
		int a[5];
		turn(tm.val,a);
		for(i=1;i<5;i++)
		{
			swap(a[i-1],a[i]);
			int x = change(a);
			if(res[tm.sec][tm.third][x]==inf)
			{
				num tt;
				tt.pace = tm.pace + 1;
				tt.sec = tm.sec;
				tt.third = tm.third;
				tt.val = x;
				res[tm.sec][tm.third][x] = tt.pace;
				result[x] = min(result[x],tt.pace);
				que.push(tt);
			}
			swap(a[i-1],a[i]);
		}
		int b[5];
		if(tm.sec>0)
		{
			for(i=0;i<5;i++)
			{
				for(j=0;j<5;j++)
				{
					b[j] = a[j];
				}
				b[i] = (a[i] + 1) % 10;
				int x = change(b);
				if(res[tm.sec-1][tm.third][x]==inf)
				{
					num tt;
					tt.pace = tm.pace + 1;
					tt.sec = tm.sec - 1;
					tt.third = tm.third;
					tt.val = x;
					res[tm.sec-1][tm.third][x] = tt.pace;
					result[x] = min(result[x],tt.pace);
					que.push(tt);
				}
			}
		}
		if(tm.third>0)
		{
			for(i=0;i<5;i++)
			{
				for(j=0;j<5;j++)
				{
					b[j] = a[j];
				}
				b[i] = (a[i] * 2) % 10;
				int x = change(b);
				if(res[tm.sec][tm.third-1][x]==inf)
				{
					num tt;
					tt.pace = tm.pace + 1;
					tt.sec = tm.sec;
					tt.third = tm.third - 1;
					tt.val = x;
					res[tm.sec][tm.third-1][x] = tt.pace;
					result[x] = min(result[x],tt.pace);
					que.push(tt);
				}
			}
		}
	}
}
int main()
{
	int now = 12345;
	int m,i,j,k;
	for(i=0;i<=3;i++)
		for(j=0;j<=2;j++)
			for(k=0;k<100000;k++) res[i][j][k] = inf;
	fill(result,result+100003,inf);
	res[3][2][now] = 0;
	result[now] = 0;
	bfs(now);
	while(~scanf("%d",&m))
	{
		if(result[m]==inf) printf("-1\n");
		else printf("%d\n",result[m]);
	}
	/*int c[5];
	int m;
	int i;
	while(~scanf("%d",&m))
	{
		turn(m,c);
		for(i=0;i<5;i++) printf("%d",c[i]);
		int x = change(c);
		printf("%d\n",x);
	}
	*/
}