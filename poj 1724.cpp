#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
struct road
{
	int t,dis,cost;
};
int minlen = 1 << 30;
int visited[110];
int totallen;
int totalcost;
int minl[110][10100];
vector<road> g[110];
void dfs(int s)
{
	if()
}
int main()
{
	int k,n,r;
	scanf("%d %d %d",&k,&n,&r);
	memset(visited,0,sizeof(visited));
	int i,tm1;
	road tm2;
	for(i=0;i<r;i++) 
	{
		scanf("%d %d %d %d",&tm1,&tm2.t,&tm2.dis,&tm2.cost);
		g[tm1].push_back(tm2);
	}
	dfs(1);

}