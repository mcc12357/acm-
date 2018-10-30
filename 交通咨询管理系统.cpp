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
};//头结点不放信息
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
		printf("删除城市不存在!\n");
		return ;
	}
	while(p->next!=NULL && strcmp(p->next->name,tm))
	{
		p = p->next;
	}
	if(p->next==NULL) 
	{
		printf("删除城市不存在!\n");
		return;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	printf("删除成功!\n");
}
void addcityinf()
{
	printf("请输入添加的城市:\n");
	char tm[20];
	scanf(" %s",tm);
	insertlink(tm);
	printf("添加成功!\n");
}
void deletecityinf()
{
	printf("请输入要删除的城市:\n");
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
	printf("请输入出发城市:\n");
	scanf(" %s",a);
	printf("请输入到达城市:\n");
	scanf(" %s",b);
	int m = searchcitynum(a);
	int n = searchcitynum(b);
	int th,tm,eh,em,tcost;
	printf("请输入出发时间:\n");
	scanf("%d %d",&th,&tm);
	printf("请输入到达时间:\n");
	scanf("%d %d",&eh,&em);
	printf("请输入所需花费:\n");
	scanf("%d",&tcost);
	map[m][n].starthour = th;
	map[m][n].startmin = tm;
	map[m][n].arrivalhour = eh;
	map[m][n].arrivalmin = em;
	map[m][n].cost = tcost;
	g[m].push_back(n);
	p[m][n] = 1;
	printf("添加成功!\n");
}
void addtraffic()
{
	printf("请选择交通方式，火车为1，飞机为0:\n");
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
	printf("请输入出发城市:\n");
	scanf(" %s",a);
	printf("请输入到达城市:\n");
	scanf(" %s",b);
	m = searchcitynum(a);
	n = searchcitynum(b);
	//for(i=0;i<g[m].size();i++) printf("%d\n",g[m][i]);
	for(Iter = g[m].begin(); Iter != g[m].end(); Iter++) 
	{ 
		if(*Iter == n) 
		{ 
			g[m].erase(Iter);
			//Iter = g[m].begin(); //当erase后，旧的容器会被重新整理成一个新的容器
		} 
		if(Iter==g[m].end()) break;
	}
	p[m][n] = 0;
	//for(i=0;i<g[m].size();i++) printf("%d\n",g[m][i]);
}
void deletetraffic()
{
	printf("请选择交通方式，火车为1，飞机为0:\n");
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
	if(mint==inf) printf("该路径不存在!\n");
	else
	{
		minth = mint / 60;
		mintm = mint - mint / 60;
		printf("最短时间为: %d %d\n",minth,mintm);
	}
}*/
void fastway()
{
	floydfast(train,g1,p1,fasttrain);
	floydfast(plane,g2,p2,fastplane);
	int k;
	while(1)
	{
		printf("请选择交通方式，火车为1，飞机为0，按2退出查询:\n");
		scanf("%d",&k);
		if(k==2) break;
		char a[20],b[20];
		printf("请输入出发城市:\n");
		scanf(" %s",a);
		printf("请输入到达城市:\n");
		scanf(" %s",b);
		int m = searchcitynum(a);
		int n = searchcitynum(b);
		if(k) 
		{
			printf("最短时间为：%d %d\n",fasttrain[m][n]/60,fasttrain[m][n]-fasttrain[m][n]/60*60);
		}
		else 
		{
			printf("最短时间为：%d %d\n",fastplane[m][n]/60,fastplane[m][n]-fastplane[m][n]/60*60);
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
		printf("请选择交通方式，火车为1，飞机为0，按2退出查询:\n");
		scanf("%d",&k);
		if(k==2) break;
		char a[20],b[20];
		printf("请输入出发城市:\n");
		scanf(" %s",a);
		printf("请输入到达城市:\n");
		scanf(" %s",b);
		int m = searchcitynum(a);
		int n = searchcitynum(b);
		//printf("%d %d\n",m,n);
		if(k) 
		{
			printf("最少花费为：%d\n",cheaptrain[m][n]);
		}
		else 
		{
			printf("最少花费为：%d\n",cheapplane[m][n]);
		}
	}
}
int main()
{
	printf("欢迎进入全国交通咨询系统!\n");
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
		printf("1.添加城市信息!\n");
		printf("2.删除城市信息!\n");
		printf("3.增加航班!\n");
		printf("4.删除航班!\n");
		printf("5.规划最快路径!\n");
		printf("6.规划最省钱路径!\n");
		printf("请输入要进行的操作:\n");
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