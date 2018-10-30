#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int maxheight = 1;
struct Node
{
	int height;
	Node *leftchild,*rightchild;
	Node()
	{
		height = 0;
		leftchild = NULL;
		rightchild = NULL;
	}
};
void build(Node *root,int height)
{
	root->height = height;
	if(height>maxheight)
	{
		root->leftchild = NULL;
		root->rightchild = NULL;
		return ;
	}
	Node *leftchild,*rightchild;
	leftchild = (Node*)malloc(sizeof(Node));
	rightchild = (Node*)malloc(sizeof(Node));
	root->leftchild = leftchild;
	root->rightchild = rightchild;
	build(leftchild,height+1);
	build(rightchild,height+1);
	/*Node leftchild = Node();
	Node rightchild = Node();
	root->leftchild = &leftchild;
	root->rightchild = &rightchild;
	build(&leftchild,height+1);
	build(&rightchild,height+1);*/
}
void show(Node *root)
{
	if(!root) return ;
	printf("current height = %d\n",root->height);
	if(root->leftchild) show(root->leftchild);
	if(root->rightchild) show(root->rightchild);
}
int main()
{
	/*Node root;
	build(&root,0);
	show(&root);*/
	Node *root;
	root = (Node*)malloc(sizeof(Node));
	build(root,0);
	show(root);
}