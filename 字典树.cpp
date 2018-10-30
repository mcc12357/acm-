#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
const int sonsum = 26,base = 'a';
char s1[12],ss[12];
struct Trie
{
	int num;
	bool flag;
	Trie *son[sonsum];
	Trie()
	{
		num = 1;
		flag = false;
		memset(son,NULL,sizeof(son));
	}
};

Trie *newTrie()
{
	Trie *temp = new Trie;
	return temp;
}

void insert(Trie *root,char *s)
{
	Trie *temp = root;
	while(*s)
	{
		if(temp->son[*s-base]==NULL)
		{
			temp->son[*s-base] = newTrie();
		}
		else
		{
			temp->son[*s-base]->num++;
		}
		temp = temp->son[*s-base];
		s++;
	}
	temp->flag = true;
}

int search(Trie *root,char *s)
{
	Trie *temp = root;
	while(*s)
	{
		if(temp->son[*s-base]==NULL) return 0;
		temp = temp->son[*s-base];
		s++;
	}
	return temp->num;
}

int main()
{
	Trie *root = newTrie();
	root->num = 0;
	while(gets(s1) && strcmp(s1,"")!=0)
	{
		insert(root,s1);
	}
	while(~scanf("%s",ss))
	{
		int ans = search(root,ss);
		printf("%d\n",ans);
	}
}
