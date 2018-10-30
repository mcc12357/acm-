#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
typedef _int64 LL;
typedef pair<LL, int> PLI;
const int MX = 2e5 + 5;
const int INF = 0x3f3f3f3f;
struct Node 
{
	Node *Next[2];
	Node() 
	{
		Next[0] = Next[1] = NULL;
	}
};
void trie_add(Node*root, int S) 
{
	Node *p = root;
	int i;
	for(i = 31; i >= 0; i--) 
	{
		int id = ((S & (1 << i)) != 0);
		if(p->Next[id] == NULL) 
		{
			p->Next[id] = new Node();
		}
		p = p->Next[id];
	}
}
int trie_query(Node*root, int S) 
{
	Node *p = root;
	int ans = 0,i;
	for(i = 31; i >= 0; i--) 
	{
		int id = ((S & (1 << i)) != 0);
		if(p->Next[id ^ 1] != NULL) 
		{
			ans |= (1 << i);
			p = p->Next[id ^ 1];
		} 
		else 
		{
			//ans |= id << i;
			p = p->Next[id];
		}
	}
	return ans;
}
int main() 
{
//freopen("input.txt", "r", stdin);
	int T, n, Q, t, ansk = 0;
	scanf("%d", &T);
	while(T--) 
	{
		scanf("%d%d", &n, &Q);
		Node *root = new Node();
		int i;
		for(i = 1; i <= n; i++) 
		{
			scanf("%d", &t);
			trie_add(root, t);
		}
		printf("Case #%d:\n", ++ansk);
		while(Q--) 
		{
			scanf("%d", &t);
			printf("%d\n", trie_query(root, t));
		}
	}
	return 0;
}
/*
3
2 2
8 16
8
16

1
2 1
1048576 8
1048576
*/