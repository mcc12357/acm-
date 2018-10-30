#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#include<stack>
#include<algorithm>
#define maxnum 1000
struct city
{
	char name[20];
	int num;
	city *next;
};//ͷ��㲻����Ϣ
struct traffic
{
	int starthour;
	int startmin;
	int arrivalhour;
	int arrivalmin;
	int cost;
};
const int inf = 100000;
int mint = inf;
city *cityhead;
int p1[maxnum][maxnum],p2[maxnum][maxnum];
int fasttrain[maxnum][maxnum],fastplane[maxnum][maxnum];
int cheaptrain[maxnum][maxnum],cheapplane[maxnum][maxnum];
int visited[maxnum];
//queue<int> que;
traffic train[maxnum][maxnum];
traffic plane[maxnum][maxnum];
vector<int> g1[maxnum],g2[maxnum];
vector <int>::iterator Iter;
int tnum = 1;
int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
void initiate(int map[maxnum][maxnum])
{
	int i,j;
	for(i=0;i<maxnum;i++)
		for(j=0;j<maxnum;j++) 
		{
			if(i==j) map[i][j] = 0;
			else map[i][j] = inf;
		}
}
void initiatecity(city **head)
{
	*head = (city *)malloc(sizeof(city));
	(*head)->next = NULL;
	(*head)->num = 0;
}
void insertlink(char tm[])
{
	city *p = cityhead,*q;
	while(p->next!=NULL) p = p->next;
	q = (city *)malloc(sizeof(city));
	strcpy(q->name,tm);
	q->num = tnum;
	tnum++;
	q->next = NULL;
	p->next = q;
}
void deletelink(char tm[])
{
	city *p,*q;
	p = cityhead;
	if(p->next==NULL)
	{
		printf("ɾ�����в�����!\n");
		return ;
	}
	while(p->next!=NULL && strcmp(p->next->name,tm))
	{
		p = p->next;
	}
	if(p->next==NULL) 
	{
		printf("ɾ�����в�����!\n");
		return;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	printf("ɾ���ɹ�!\n");
}
void addcityinf()
{
	printf("��������ӵĳ���:\n");
	char tm[20];
	scanf(" %s",tm);
	insertlink(tm);
	printf("��ӳɹ�!\n");
}
void deletecityinf()
{
	printf("������Ҫɾ���ĳ���:\n");
	char tm[20];
	scanf(" %s",tm);
	deletelink(tm);	
}
int searchcitynum(char tm[])
{
	city *p = cityhead->next;
	while(p!=NULL && strcmp(p->name,tm)) p = p->next;
	if(p!=NULL) return p->num;
	return 0;
}
void floydfast(traffic map[maxnum][maxnum],vector<int> g[maxnum],int p[maxnum][maxnum],int d[maxnum][maxnum])
{
	int i,j,k;
	for(i=1;i<tnum;i++)
		for(j=1;j<tnum;j++)
		{
			if(i==j) d[i][j] = 0;
			else if(p[i][j]) d[i][j] = min(d[i][j],(map[i][j].arrivalhour-map[i][j].starthour)*60+map[i][j].arrivalmin-map[i][j].startmin);
			else d[i][j] = inf;
		}
	for(k=1;k<tnum;k++)
		for(i=1;i<tnum;i++)
			for(j=1;j<tnum;j++)
			{
				if(p[i][k]&&p[k][j]&&map[i][k].arrivalhour*60+map[i][k].arrivalmin<=map[k][j].starthour*60+map[k][j].startmin)
				{
					d[i][j] = min(d[i][j],(map[k][j].arrivalhour-map[i][k].starthour)*60+map[k][j].arrivalmin-map[i][k].startmin);
					p[i][j] = 1;
				}
			}
}
void floydcheap(traffic map[maxnum][maxnum],vector<int> g[maxnum],int p[maxnum][maxnum],int d[maxnum][maxnum])
{
	int i,j,k;
	for(i=1;i<tnum;i++)
		for(j=1;j<tnum;j++)
		{
			if(i==j) d[i][j] = 0;
			else if(p[i][j]) d[i][j] = min(d[i][j],map[i][j].cost);
			else d[i][j] = inf;
		}
	for(k=1;k<tnum;k++)
		for(i=1;i<tnum;i++)
			for(j=1;j<tnum;j++)
			{
				if(p[i][k]&&p[k][j]&&map[i][k].arrivalhour*60+map[i][k].arrivalmin<=map[k][j].starthour*60+map[k][j].startmin)
				{
					d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
					p[i][j] = 1;
				}
			}
}
void addmap(traffic map[maxnum][maxnum],vector<int> g[maxnum],int p[maxnum][maxnum])
{
	char a[20],b[20];
	printf("�������������:\n");
	scanf(" %s",a);
	printf("�����뵽�����:\n");
	scanf(" %s",b);
	int m = searchcitynum(a);
	int n = searchcitynum(b);
	int th,tm,eh,em,tcost;
	printf("���������ʱ��:\n");
	scanf("%d %d",&th,&tm);
	printf("�����뵽��ʱ��:\n");
	scanf("%d %d",&eh,&em);
	printf("���������軨��:\n");
	scanf("%d",&tcost);
	map[m][n].starthour = th;
	map[m][n].startmin = tm;
	map[m][n].arrivalhour = eh;
	map[m][n].arrivalmin = em;
	map[m][n].cost = tcost;
	g[m].push_back(n);
	p[m][n] = 1;
	printf("��ӳɹ�!\n");
}
void addtraffic()
{
	printf("��ѡ��ͨ��ʽ����Ϊ1���ɻ�Ϊ0:\n");
	int k;
	scanf("%d",&k);
	if(k) 
	{
		addmap(train,g1,p1);
//		floydfast(train,g1,p1,fasttrain);
//		floydcheap(train,g1,p1,cheaptrain);
	}
	else 
	{
		addmap(plane,g2,p2);
//		floydfast(plane,g2,p2,fastplane);
//		floydcheap(plane,g2,p2,cheapplane);
	}
}
void deletemap(traffic map[maxnum][maxnum],vector<int> g[maxnum],int p[maxnum][maxnum])
{
	char a[20],b[20];
	int m,n;
	printf("�������������:\n");
	scanf(" %s",a);
	printf("�����뵽�����:\n");
	scanf(" %s",b);
	m = searchcitynum(a);
	n = searchcitynum(b);
	//for(i=0;i<g[m].size();i++) printf("%d\n",g[m][i]);
	for(Iter = g[m].begin(); Iter != g[m].end(); Iter++) 
	{ 
		if(*Iter == n) 
		{ 
			g[m].erase(Iter);
			//Iter = g[m].begin(); //��erase�󣬾ɵ������ᱻ���������һ���µ�����
		} 
		if(Iter==g[m].end()) break;
	}
	p[m][n] = 0;
	//for(i=0;i<g[m].size();i++) printf("%d\n",g[m][i]);
}
void deletetraffic()
{
	printf("��ѡ��ͨ��ʽ����Ϊ1���ɻ�Ϊ0:\n");
	int k;
	scanf("%d",&k);
	if(k) deletemap(train,g1,p1);
	else deletemap(plane,g2,p2);
}
/*void dfsfast(int m,int n,traffic map[maxnum][maxnum],vector<int> g[maxnum],int t)
{
	visited[m] = 1;
	if(m==n)
	{
		if(t<mint) mint = t;
		return;
	}
	int i;
	for(i=0;i<g[m].size();i++) 
	{
		if(visited[i]) continue;
		t += (map[m][i].arrivalhour-map[m][i].starthour)*60 + map[m][i].arrivalmin - map[m][i].startmin;
		visited[i] =1;
		dfsfast(i,n,map,g,t);
		visited[i] = 0;
	}
	visited[m] = 0;
}*/
/*void searchfastway(traffic map[maxnum][maxnum],vector<int> g[maxnum])
{
	
	//memset(visited,0,sizeof(visited));
	//while(!que.empty()) que.pop();
	dfsfast(m,n,map,g,0);
	int minth,mintm;
	if(mint==inf) printf("��·��������!\n");
	else
	{
		minth = mint / 60;
		mintm = mint - mint / 60;
		printf("���ʱ��Ϊ: %d %d\n",minth,mintm);
	}
}*/
void fastway()
{
	floydfast(train,g1,p1,fasttrain);
	floydfast(plane,g2,p2,fastplane);
	int k;
	while(1)
	{
		printf("��ѡ��ͨ��ʽ����Ϊ1���ɻ�Ϊ0����2�˳���ѯ:\n");
		scanf("%d",&k);
		if(k==2) break;
		char a[20],b[20];
		printf("�������������:\n");
		scanf(" %s",a);
		printf("�����뵽�����:\n");
		scanf(" %s",b);
		int m = searchcitynum(a);
		int n = searchcitynum(b);
		if(k) 
		{
			printf("���ʱ��Ϊ��%d %d\n",fasttrain[m][n]/60,fasttrain[m][n]-fasttrain[m][n]/60*60);
		}
		else 
		{
			printf("���ʱ��Ϊ��%d %d\n",fastplane[m][n]/60,fastplane[m][n]-fastplane[m][n]/60*60);
		}
	}
}
void cheapway()
{
	floydcheap(train,g1,p1,cheaptrain);
	floydcheap(plane,g2,p2,cheapplane);
	int k;
	while(1)
	{
		printf("��ѡ��ͨ��ʽ����Ϊ1���ɻ�Ϊ0����2�˳���ѯ:\n");
		scanf("%d",&k);
		if(k==2) break;
		char a[20],b[20];
		printf("�������������:\n");
		scanf(" %s",a);
		printf("�����뵽�����:\n");
		scanf(" %s",b);
		int m = searchcitynum(a);
		int n = searchcitynum(b);
		//printf("%d %d\n",m,n);
		if(k) 
		{
			printf("���ٻ���Ϊ��%d\n",cheaptrain[m][n]);
		}
		else 
		{
			printf("���ٻ���Ϊ��%d\n",cheapplane[m][n]);
		}
	}
}
int main()
{
	printf("��ӭ����ȫ����ͨ��ѯϵͳ!\n");
	int x;
	initiate(fasttrain);
	initiate(fastplane);
	initiate(cheaptrain);
	initiate(cheapplane);
	initiatecity(&cityhead);
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	//initiatemap(train);
	//initiatemap(plane);
	while(1)
	{
		printf("********************************************************************************\n");
		printf("1.��ӳ�����Ϣ!\n");
		printf("2.ɾ��������Ϣ!\n");
		printf("3.���Ӻ���!\n");
		printf("4.ɾ������!\n");
		printf("5.�滮���·��!\n");
		printf("6.�滮��ʡǮ·��!\n");
		printf("������Ҫ���еĲ���:\n");
		scanf("%d",&x);
		switch(x)
		{
		case 1:addcityinf();break;
		case 2:deletecityinf();break;
		case 3:addtraffic();break;
		case 4:deletetraffic();break;
		case 5:fastway();break;
		case 6:cheapway();break;
		case 0:exit(0);break;
		}
	}
	return 0;
}