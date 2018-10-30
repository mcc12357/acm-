#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
int w = 10,h = 10,n = 5;
int x1[] = {1,1,4,9,10};
int x2[] = {6,10,4,9,10};
int y1[] = {4,8,1,1,6};
int y2[] = {4,8,10,5,10};
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
bool fld[50][50];
int compress(int *x1,int *x2,int w)
{
	vector<int> xs;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=-1;j<=1;j++)//将相邻两排和自己这一排存起来
		{
			int tx1 = x1[i] + j,tx2 = x2[i] + j;
			if(tx1>=1 && tx1<=w) xs.push_back(tx1);
			if(tx2>=1 && tx1<=w) xs.push_back(tx2);
		}
	}
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());//删除同样的元素
	for(i=0;i<n;i++)
	{
		x1[i] = find(xs.begin(),xs.end(),x1[i]) - xs.begin();
		x2[i] = find(xs.begin(),xs.end(),x2[i]) - xs.begin();
	}
	return xs.size();
}
int main()
{
	w = compress(x1,x2,w);
	h = compress(y1,y2,h);
	memset(fld,0,sizeof(fld));
	int i,x,y;
	for(i=0;i<n;i++)
	{
		for(y=y1[i];y<=y2[i];y++)//如果是同一列则y1[i]=y2[i]
			for(x=x1[i];x<=x2[i];x++)//如果是同一行则x1[i]=x2[i]
			{
				fld[y][x] = true;
			}
	}
	int ans = 0;//求区域的个数
	for(y=0;y<h;y++)
		for(x=0;x<w;x++)
		{
			if(fld[y][x]) continue;
			ans++;
			queue<pair<int,int> > que;
			que.push(make_pair(x,y));
			while(!que.empty())
			{
				int sx = que.front().first,sy = que.front().second;
				que.pop();
				for(i=0;i<4;i++)
				{
					int tx = sx + dx[i];
					int ty = sy + dy[i];
					if(tx<0 || w<=tx || ty<0 || h<=ty) continue;
					if(fld[ty][tx]) continue;
					que.push(make_pair(tx,ty));
					fld[ty][tx] = true;
				}
			}
		}
	printf("%d\n",ans);
}