#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
int vnum,snum;
double dx[505],dy[505],dis[505][505];
double mincost[505];
bool used[505];
double res[505];
const float inf = 100000;
float cal(int i,int j)
{
	return sqrt((dx[i]-dx[j]) * (dx[i]-dx[j]) + (dy[i]-dy[j]) * (dy[i]-dy[j]));
}
float min(float x,float y)
{
	if(x<y) return x;
	return y;
}
bool cmp(float x,float y)
{
	return x>y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&snum,&vnum);
		int i,j;
		for(i=0;i<vnum;i++) scanf("%lf %lf",&dx[i],&dy[i]);
		for(i=0;i<vnum;i++) 
			for(j=0;j<vnum;j++) 
			{
				if(i==j) {dis[i][j] = 0;continue;}
				dis[i][j] = cal(i,j);
			}
		for(i=0;i<vnum;i++)
		{
			mincost[i] = inf;
			used[i] = false;
		}
		mincost[0] = 0;
		int k = 0;
		while(true)
		{
			int v = -1;
			int u;
			for(u=0;u<vnum;u++)
			{
				if(!used[u] && (v==-1 || mincost[u]<mincost[v])) v = u;
			}
			if(v==-1) break;
			used[v] = true;
			res[k++] = mincost[v];
			for(u=0;u<vnum;u++)
			{
				mincost[u] = min(mincost[u],dis[v][u]);
			}
		}
		sort(res,res+k,cmp);
		//printf("%d\n",k);
		//for(i=0;i<4;i++) printf("%.2f\n",res[i]);
		printf("%.2f\n",res[snum-1]);
	}
}
/*
4
3 4
1 100
0 150
50 100
2 300
*/