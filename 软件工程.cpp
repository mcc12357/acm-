#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<set>
#define maxn 500
vector<string> line[50];
int stationnum = 0;
int linenum = 0;
vector<int> station[maxn];
set<string> S;
set<string>::iterator is;
map<string,int> M;
bool used[505][505];
bool vis[505];
bool flag;
string sta[505];
int kind;
int num;
//map<string,int>::iterator im;
void load()
{
	ifstream in("C:\\test.txt");
	string filename;
	string str;
	int i,j;
	if(in)
	{
		while(getline(in,str))
		{
			//cout<<str<<endl;
			int tline,tnum;
			string tname;
			int s = 0,t = 0;
			while(s<str.size() && t<str.size())
			{
				while(str[t]!=' ') t++;
				string tm;
				tm = str.substr(s,t-s);
				line[linenum].push_back(tm);
				t++;
				s = t;
			}
			linenum++;
		}
	}
	for(i=0;i<linenum;i++)
	{
		for(j=0;j<line[i].size();j++)
		{
			string cur = line[i][j];
			is = S.find(cur);
			if(is==S.end())
			{
				M[cur] = stationnum;
				sta[stationnum] = cur;
				S.insert(cur);
				stationnum++;
			}
		}
	}
	for(i=0;i<linenum;i++)
	{
		for(j=0;j<line[i].size()-1;j++)
		{
			string cur = line[i][j];
			string nxt = line[i][j+1];
			if(!used[M[cur]][M[nxt]])
			{
				station[M[cur]].push_back(M[nxt]);
				station[M[nxt]].push_back(M[cur]);
				used[M[cur]][M[nxt]] = true;
				used[M[nxt]][M[cur]] = true;
			}
		}
	}
}
void show()
{
	printf("请输入想要进行的操作：\n");
	printf("1、输出任意线路所有车站\n");
	printf("2、查询任意两个车站之间的路线\n");
	printf("3、任选起点遍历所有车站\n");
}
void fun1()
{
	printf("请输入需要查询的铁路线路：\n");
	int tl;
	scanf("%d",&tl);
	int i;
	for(i=0;i<line[tl-1].size();i++) cout<<line[tl-1][i]<<endl;
}
void dfs(int x,int k,int ee,int res[])
{
	if(flag) return ;
	vis[k] = true;
	res[k] = x;
	num = k;
	if(x==ee)
	{
		flag = true;
		return ;
	}
	int i;
	for(i=0;i<station[x].size();i++)
	{
		int v = station[x][i];
		if(!vis[v])
		{
			dfs(v,k+1,ee,res);
		}
	}
}
void fun2()
{
	string start,end;
	printf("请输入要查询的两个站点：\n");
	printf("起点站：\n");
	cin>>start;
	printf("终点站：\n");
	cin>>end;
	int ss = M[start];
	int ee = M[end];
	int res[505];
	memset(vis,0,sizeof(vis));
	flag = false;
	num = 0;
	memset(res,-1,sizeof(res));
	dfs(ss,num,ee,res);
	int i;
	//cout<<num<<endl;
	printf("输出路线为：\n");
	for(i=0;i<=num;i++)
	{
		cout<<sta[res[i]]<<endl;
	}
}
void ndfs(int x,int par,int k,int res[])
{
	if(kind==stationnum)
	{
		return ;
	}
	if(par>=0)
	{
		used[par][x] = true;
	}
	if(!vis[x])
	{
		vis[x] = true;
		kind++;
	}
	res[k] = x;
	num = k;
	int i;
	for(i=0;i<station[x].size();i++)
	{
		int v = station[x][i];
		if(used[x][v]) continue;
		ndfs(v,x,k+1,res);
	}	
}
void fun3()
{
	printf("请输入想要开始的起点：\n");
	string start;
	cin>>start;
	int ss = M[start];
	memset(vis,0,sizeof(vis));
	memset(used,0,sizeof(used));
	flag = false;
	num = 0;
	kind = 0;
	int res[505];
	ndfs(ss,-1,num,res);
	int i;
	printf("遍历路线为：\n");
	for(i=0;i<=num;i++) cout<<sta[res[i]]<<endl;
}
int main()
{
	printf("欢迎进入北京铁路查询系统！\n\n");
	load();
	show();
	int st;
	while(~scanf("%d",&st))
	{
		switch(st)
		{
			case 1: fun1();break;
			case 2: fun2();break;
			case 3: fun3();break;
			default:break;
		}
	}
}