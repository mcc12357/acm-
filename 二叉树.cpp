#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
struct node
{
	char data;
	node *leftchild;
	node *rightchild;
};
void initiate(node **root)
{
	*root = (node *)malloc(sizeof(node));
	(*root)->leftchild = NULL;
	(*root)->rightchild = NULL;
}
void build(node *root,char a[],char b[],int start1,int end1,int start2,int end2)
{
	if(start1==end1 && start2==end2) 
	{
		root->leftchild = NULL;
		root->rightchild = NULL;
		return ;
	}
	int i,j;
	for(i=start2;i<=end2;i++) if(a[start1]==b[i]) break;//iΪ���ڵ�
	if(i==start2) root->leftchild = NULL;
	if(i!=start2)
	{
		node *p;
		p = (node *)malloc(sizeof(node));
		root->leftchild = p;
		p->data = a[start1+1];
		build(p,a,b,start1+1,i-start2+start1,start2,i-1);
	}
	if(i==end2) root->rightchild = NULL;
	if(i!=end2)
	{
		node *q;
		q = (node *)malloc(sizeof(node));
		root->rightchild = q;
		q->data = a[i-start2+start1+1];
		build(q,a,b,end1-end2+i+1,end1,i+1,end2);
	}
	return;
}
void visit(char m)
{
	printf("%c",m);
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		visit(root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->leftchild);
		visit(root->data);
		inorder(root->rightchild);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		visit(root->data);
	}
}
void print(node *root,int n)
{
	int i;
	if(root==NULL) return ;
	print(root->rightchild,n+1);
	for(i=0;i<n-1;i++) printf("     ");
	if(n>0)
	{
		printf("---");
		printf("%c\n",root->data);
	}
	print(root->leftchild,n+1);
}
int main()
{
	node *root;
	initiate(&root);
	char a[100],b[100];//a���ǰ����������b�������������
	int n,i;
	/*printf("������ڵ������");
	scanf("%d",&n);
	getchar();*/
	printf("������ǰ����������");
	/*for(i=0;i<n;i++) scanf("%c",&a[i]);
	a[n] = '\0';
	getchar();*/
	scanf("%s",a);
	printf("������������������");
	/*for(i=0;i<n;i++) scanf("%c",&b[i]);
	b[n] = '\0';*/
	scanf("%s",b);
	n = strlen(a);
	for(i=0;i<n;i++) if(b[i]==a[0]) break;
	root->data = a[0];
	build(root,a,b,0,n-1,0,n-1);
	printf("ǰ��������Ϊ�� ");
	preorder(root);
	printf("\n");
	printf("����������Ϊ�� ");
	inorder(root);
	printf("\n");
	printf("����������Ϊ�� ");
	postorder(root);
	printf("\n");
	printf("���뷨�����������\n");
	print(root,5);
}
/*
ABDGCEF
DGBAECF
*/