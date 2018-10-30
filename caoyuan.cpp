#include<iostream>
using namespace std;
#include<queue>
#include<string.h>
#include<stdio.h>
struct pcb
{
	char name[8];
	int need;
	int turn;
	struct pcb *next;
};
pcb *rq1,*rq2;
int clock = 0,time;//时间片为time
void initiate(pcb **head)
{
	*head = (pcb *)malloc(sizeof(pcb));
	(*head)->next = NULL;
}
void insert1(pcb *rq,int t1,int t2)
{
	pcb *p = rq;
	while(p->next!=NULL) p = p->next;
	pcb *q;
	q = (pcb *)malloc(sizeof(pcb));
	q->need = t1;
	q->turn = t2;
	p->next = q;
	q->next = NULL;
}
void insert2(pcb *rq,int t1,int t2)
{
	pcb *p = rq;
	while(p->next!=NULL || p->next->need>t2) p = p->next;
	pcb *q;
	q = (pcb *)malloc(sizeof(pcb));
	q->need = t1;
	q->turn = t2;
	q->next = p->next;
	p->next = q;
}
void cal(queue<pcb*> que,pcb *rq)
{
	if(time>=rq->need) 
	{
		clock += rq->need;
		rq->turn += (clock - rq->need);
	}
	else
	{
		rq->need -= time;
		rq->turn -= time;
		clock += time;
		que.push(rq);
	}
	//return rq.turn;
}
void qcal(queue <pcb*>que,pcb *p)
{
	if(time>=p->need)
	{
		clock += p->need;
		p->turn += (clock - p->need);
	}
	else
	{
		p->need -= time;
		p->turn -= time;
		clock += time;
		que.push(p);
	}
	//return p.turn;
}
int main()
{
	int m,n;
	scanf("%d %d %d",&time,&m,&n);//m为rq1进程数,n为rq2进程数
	//rq1->next = NULL;
	//rq2->next = NULL;
	initiate(&rq1);
	initiate(&rq2);
	pcb *s1 = rq1;
	pcb *s2 = rq2;
	int i,t1,t2;
	queue <pcb*>que;
	for(i=1;i<=m;i++) 
	{
		scanf("%d %d",&t1,&t2);
		insert1(rq1,t1,t2);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&t1,&t2);
		insert2(rq2,t1,t2);
	}
	while(s1->next!=NULL)
	{
		/*pcb temp;
		temp.need = rq1->need;
		temp.turn = rq1->turn;*/
		cal(que,s1);
		s1 = s1->next;
	}
	while(!que.empty())
	{
		pcb *temp;
		temp = que.front();
		que.pop();
		qcal(que,temp);
	}
	while(s2->next!=NULL)
	{
		/*pcb temp;
		temp.need = rq2->need;
		temp.turn = rq2->turn;*/
		cal(que,s2);
		s2 = s2->next;
	}
	while(!que.empty())
	{
		pcb *temp;
		temp = que.front();
		que.pop();
		qcal(que,temp);
	}
	pcb *w1 = rq1->next;
	while(w1->next!=NULL) 
	{
		printf("%d\n",w1->turn);
		w1 = w1->next;
	}
	w1 = rq2;
	while(w1->next!=NULL)
	{
		printf("%d\n",w1->turn);
		w1 = w1->next;
	}
}