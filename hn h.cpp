#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1000010
const int inf = 1000010;
int a[maxn],sum[maxn];
int res;
int Left,Right;
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
struct Node 
{
	Node *next[2];
	int index;
	Node()
	{
		next[0] = next[1] = NULL;
		index = inf;
	}
};
void trie_add(Node *root,int s,int x)
{
	Node *p = root;
	int i;
	for(i=31;i>=0;i--)
	{
		int id = ((s & (1 << i))!= 0);
		if(p->next[id]==NULL)
		{
			p->next[id] = new Node();
		}
		p = p->next[id];
		if(i==0) p->index = min(x,p->index);
	}
}
void trie_query(Node *root,int s,int x)
{
	Node *p = root;
	int ans = 0;
	int i,tm;
	for(i=31;i>=0;i--)
	{
		int id = ((s & (1 << i)) != 0);
		if(p->next[id ^ 1] != NULL)
		{
			ans |= (1 << i);
			p = p->next[id ^ 1];
		}
		else
		{
			p = p->next[id];
		}
		if(i==0) tm = p->index;
	}
	if(ans>=res)
	{
		if(ans>res)
		{
			res = ans;
			Left = tm;
			Right = x;
		}
		else if(Left>tm)
		{
			Left = tm;
			Right = x;
		}
		else if(Left==tm) Right = min(Right,x);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int count = 1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		memset(sum,0,sizeof(sum));
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sum[0] = 0;
		for(i=1;i<=n;i++) sum[i] = sum[i-1] ^ a[i];
		res = 0;
		Left = Right = inf;
		Node *root = new Node();
		trie_add(root,sum[0],0);
		for(i=1;i<=n;i++)
		{
			trie_query(root,sum[i],i);
			trie_add(root,sum[i],i);
		}
		printf("Case #%d:\n",count);
		count++;
		printf("%d %d\n",Left+1,Right);
		//printf("%d %d %d %d\n",sum[0],sum[1],sum[2],sum[3]);
	}
}