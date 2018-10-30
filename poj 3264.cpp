#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 200000//注意数组最好开4*n大小，不要开小了
int n,q;
int mmin[maxn],mmax[maxn];
int max(int x,int y) 
{
	if(x>y) return x;
	return y;
}
int min(int x,int y) 
{
	if(x<y) return x;
	return y;
}
void pushup(int rt)
{
	mmax[rt] = max(mmax[rt<<1],mmax[rt<<1|1]);
	mmin[rt] = min(mmin[rt<<1],mmin[rt<<1|1]);
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		return ;
	}
	int m = (l + r) / 2;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
void update(int x,int k,int l,int r,int rt)
{
	if(l==r)
	{
		mmax[rt] = k;
		mmin[rt] = k;
		return ;
	}
	int m = (l + r) / 2;
	if(x<=m) update(x,k,l,m,rt<<1);
	if(x>m) update(x,k,m+1,r,rt<<1|1);
	pushup(rt);
}
int querymax(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		return mmax[rt];
	}
	int m = (l + r) / 2;
	int ret = -1;
	if(L<=m) ret = max(ret,querymax(L,R,l,m,rt<<1));
	if(R>m) ret = max(ret,querymax(L,R,m+1,r,rt<<1|1));
	return ret;
}
int querymin(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		return mmin[rt];
	}
	int m = (l + r) / 2;
	int ret = 2000000;
	if(L<=m) ret = min(ret,querymin(L,R,l,m,rt<<1));
	if(R>m) ret = min(ret,querymin(L,R,m+1,r,rt<<1|1));
	return ret;
}
int main()
{
	scanf("%d %d",&n,&q);
	build(1,n,1);
	int i,tm;
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&tm);
		update(i,tm,1,n,1);
	}
	for(i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int res = querymax(l,r,1,n,1) - querymin(l,r,1,n,1);
		printf("%d\n",res);
	}
}

