#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
typedef _int64 ll;
#define maxn 200010
ll maxW,maxH;//�����Լ�����
int preW[maxn],preH[maxn];
int rankW[maxn],rankH[maxn];
int visW[maxn],visH[maxn];
int op[maxn];
char opt[3];
int num[maxn];
int w,h,n;
ll ans[maxn];
ll max(ll x,ll y)
{
	if(x>y) return x;
	return y;
}
inline void scan_d(int &ret)//���ڶ�������abc 123��ʽ�е�123�����ұ���ʹ��cin
{
	char c;
	ret = 0;
	while((c = getchar()) < '0' || c > '9');
	while(c>='0' && c<='9')
	{
		ret = ret * 10 + (c - '0'),c = getchar();
	}
}
void init()
{
	int i;
	for(i=0;i<=w;i++) 
	{
		preW[i] = i;
		rankW[i] = 1;
	}
	for(i=0;i<=h;i++)
	{
		preH[i] = i;
		rankH[i] = 1;
	}
	memset(visW,0,sizeof(visW));
	memset(visH,0,sizeof(visH));
	memset(op,0,sizeof(op));
}
int findW(int x)
{
	if(preW[x]!=x) preW[x] = findW(preW[x]);
	return preW[x];
}
void joinW(int x,int y)
{
	x = findW(x);
	y = findW(y);
	if(x==y) return ;
	preW[y] = x;
	rankW[x] += rankW[y];
	maxW = max(rankW[x],maxW);
}
int findH(int x)
{
	if(preH[x]!=x) preH[x] = findH(preH[x]);
	return preH[x];
}
void joinH(int x,int y)
{
	x = findH(x);
	y = findH(y);
	if(x==y) return ;
	preH[y] = x;
	rankH[x] += rankH[y];
	maxH = max(rankH[x],maxH);
}
int main()
{
	scanf("%d %d %d",&w,&h,&n);
	init();
	rankW[0] = rankH[0] = 0;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",opt);
		scan_d(num[i]);
		if(opt[0]=='H')
		{
			op[i] = 1;
			visH[num[i]] = 1;
		}
		else
		{
			visW[num[i]] = 1;
		}
	}
	maxH = maxW = 1;
	for(i=1;i<w;i++)//��û�б��и���߶μ��벢�鼯����ô���ڵ��rank��Ϊ��һ���ֵ���󳤶ȣ���ʱ���и�����ĩ״̬
	{
		if(!visW[i])
		{
			joinW(i,i+1);
		}
	}
	for(i=0;i<h;i++)
	{
		if(!visH[i])
		{
			joinH(i,i+1);
		}
	}
	for(i=n-1;i>=0;i--)
	{
		ans[i] = maxH * maxW;
		if(op[i])
		{
			joinH(num[i],num[i]+1);//����i���и��߷��벢�鼯
		}
		else
		{
			joinW(num[i],num[i]+1);
		}
	}
	for(i=0;i<n;i++) printf("%I64d\n",ans[i]);
}