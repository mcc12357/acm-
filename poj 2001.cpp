#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
const int sonnum = 26,base = 'a';
char ss[1005][25];
struct Trie
{
	int num;
	bool flag;
	Trie *son[sonnum];
	Trie()
	{
		num = 1;flag = false;
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
		else temp->son[*s-base]->num++;
		temp = temp->son[*s-base];
		s++;
	}
	temp->flag = true;
}
void search(Trie *root,char *s)
{
	Trie *temp = root;
	char *str = s;
	while(*s)
	{
		if(temp->son[*s-base]->num==1)
		{
			break;
		}
		temp = temp->son[*s-base];
		s++;
	}
	while(str<=s&&*s || str<s&&!*s)
	{
		printf("%c",*str);
		str++;
	}
	printf("\n");
}
int main()
{
	Trie *root = newTrie();
	root->num = 0;
	int count = 0,i;
	while(~scanf("%s",ss[count]))
	{
		insert(root,ss[count]);
		count++;
	}
	for(i=0;i<count;i++)
	{
		printf("%s ",ss[i]);
		search(root,ss[i]);
	}
}