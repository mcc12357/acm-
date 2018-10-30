#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int xmove[8] = {-2,-1,1,2,2,1,-1,-2},ymove[8] = {1,2,2,1,-1,-2,-2,-1};
int used[10][10],tused[10][10];
int num = 0;
struct lsnode
{
	int x;
	int y;
	lsnode *next;
};
void stackinitiate(lsnode **head)
{
	*head = (lsnode *)malloc(sizeof(lsnode));
	(*head)->next = NULL;
}
int stacknotempty(lsnode *head)
{
	if(head->next == NULL) return 0;
	else return 1;
}
void stackpush(lsnode *head,int a,int b)
{
	lsnode *p;
	p = (lsnode *)malloc(sizeof(lsnode));
	p->x = a;
	p->y = b;
	p->next = head->next;
	head->next = p;
	num++;
}
int stackpop(lsnode *head)
{
	lsnode *p = head->next;
	if(p==NULL)
	{
		//printf("堆栈已空出错!");
		return 0;
	}
	head->next = p->next;
	free(p);
	return 1;
	num--;
}
int stacktop(lsnode *head,int &a,int &b)
{
	lsnode *p = head->next;
	if(p==NULL)
	{
		//printf("堆栈已空出错!");
		return 0;
	}
	a = p->x;
	b = p->y;
	return 1;
}
void destroy(lsnode *head)
{
	lsnode *p,*p1;
	p = head;
	while(p!=NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
} 
int main()
{
	int m,n,sign = 1;
	int resx[64],resy[64];
	scanf("%d %d",&m,&n);
	lsnode *mystack;
	memset(used,0,sizeof(used));
	used[m][n] = 1;
	stackinitiate(&mystack);
	stackpush(mystack,m,n);
	memset(tused,0,sizeof(tused));
	while(stacknotempty(mystack))
	{
		int a,b,ntemp;
		int i,flag = 0;
		//memset(tused,0,sizeof(tused));
		//stackpop(mystack);
		for(i=0;i<8;i++)
		{
			stacktop(mystack,a,b);
			int nx = a + xmove[i];
			int ny = b + ymove[i];
			flag = 1;
			if(nx>=0 && nx<=7 && ny>=0 && ny<=7 && !used[nx][ny] && !tused[nx][ny])
			{
				flag = 0;
				stackpush(mystack,nx,ny);
				used[nx][ny] = 1;
			}
		}
		if(flag)
		{
			ntemp = num;
			int i,j,t = 0;
			sign = 1;
			for(i=0;i<=7;i++)
			{
				for(j=0;j<=7;j++) 
				{
					if(used[i][j]==0) 
					{
						sign = 0;
						t = 1;
					}
					if(t) break;
				}
				if(t) break; 
			}
			if(sign==1)
			{
				while(stacknotempty(mystack) && t==0)
				{
					int mx,my,k = 0;
					stacktop(mystack,resx[k],resy[k]);
					k++;
					//printf("%d %d\n",mx,my);
					stackpop(mystack);
				}
				if(t==0) for(i=63;i>=0;i--) printf("%d %d\n",resx[i],resy[i]);
			}
			if(sign==0)
			{
				//stackpop(mystack);
				if(stacknotempty(mystack)==0) continue;
				int mx;
				int my;
				stacktop(mystack,mx,my);
				tused[mx][my] = 1;
				stackpop(mystack);
				used[mx][my] = 0;
			}
		}
		if(ntemp>num) memset(tused,0,sizeof(tused));
	}
	if(sign==0) printf("遍历不成功!\n");
}