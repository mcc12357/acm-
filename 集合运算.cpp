#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
struct node
{
	char data;
	node *next;
};
void listinitiate(node **head)
{
	*head = (node *)malloc(sizeof(node));
	(*head)->next = NULL;
}
void listinsert(node *head,char x)
{
	node *p = head;
	node *q;
	q = (node *)malloc(sizeof(node));
	while(p->next!=NULL)
	{
		if(p->next->data>=x) break; 
		p = p->next;
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
}
void sdelete(node *list)
{
	 node *m = list;
	 node *n = m->next;
	 if(list->next==NULL) return;
	 //if(list->next->next==NULL) return;
	 while(m->next->next!=NULL)
	 {
		 if(m->next->data != n->next->data)
		 {
			 m = m->next;
			 n = n->next;
		 }
		 else
		 {
			 node *t = m->next;
			 m->next = n->next;
			 //m = m->next;
			 n = n->next;
			 free(t);
		 }
	 }
}
void merge(node *list1,node *list2)
{
	 node *list;
	 listinitiate(&list);
	 node *p = list1->next;
	 node *q = list2->next;
	 char y;
	 while(p->next!=NULL)
	 {
		y = p->data;
		listinsert(list,y);
		p = p->next;
	 }
	 y = p->data;
	 listinsert(list,y);
	 while(q->next!=NULL)
	 {
		y = q->data;
		listinsert(list,y);
		q = q->next;
	 }
	 y = q->data;
	 listinsert(list,y);
	 sdelete(list);
	 node *m;
	 m = list->next;
	 while(m->next!=NULL)
	 {
		 printf("%c",m->data);
		 m = m->next;
	 }
	 printf("%c\n",m->data);
}
void and(node *list1,node *list2)
{
	node *p = list1->next;
	node *q = list2->next;
	node *list;
	listinitiate(&list);
	while(p->next!=NULL)
	{
		while(q->data<p->data && q->next!=NULL) q = q->next;
		if(q->data == p->data) listinsert(list,p->data);
		p = p->next;
	}
	if(p->data==q->data) listinsert(list,p->data);
	sdelete(list);
	p = list->next;
	if(p==NULL) {printf("空集\n");return;}
	while(p->next!=NULL) {printf("%c",p->data);p = p->next;}
	printf("%c\n",p->data);
}
void minus(node *list1,node *list2)
{
	node *p = list1->next;
	node *q = list2->next;
	node *list;
	listinitiate(&list);
	while(p->next!=NULL)
	{
		while(q->data<p->data && q->next!=NULL) q = q->next;
		if(q->data != p->data) listinsert(list,p->data);
		p = p->next;
	}
	while(q->next!=NULL) if(p->data>q->data) q = q->next;
	if(p->data!=q->data) listinsert(list,p->data);
	sdelete(list);
	p = list->next;
	if(p==NULL) {printf("空集\n");return;}
	while(p->next!=NULL) {printf("%c",p->data);p = p->next;}
	printf("%c\n",p->data);
}
int main()
{
	char a;
	node *list1;
	node *list2;
	listinitiate(&list1);
	listinitiate(&list2);
	printf("Set1 = ");
	while(~scanf("%c",&a) && a>='A' && a<='Z')
	{
		listinsert(list1,a);
	}
	printf("Set2 = ");
	while(~scanf("%c",&a) && a>='A' && a<='Z')
	{
		listinsert(list2,a);
	}
	printf("Set1并Set2 = ");
	merge(list1,list2);
	printf("Set1交Set2 = ");
	and(list1,list2);
	printf("Set1-Set2 = ");
	minus(list1,list2);
}