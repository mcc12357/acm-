#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
const int M = 505;
vector<int> v[M];
bool mark[M];
int _link[M];//c++中有link，所以不能用
int n,k;
bool findpath(int i)
{
	int term,j;
	for(j=0;j<v[i].size();j++)
	{
		term = v[i][j];
		if(!mark[term])
		{
			mark[term] = true;
			if(!_link[term] || findpath(_link[term])) 
			{
				_link[term] = i;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		int i,res,a,b;
		for(i=1;i<=k;i++)
		{
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
		}
		memset(_link,0,sizeof(0));
		res = 0;
		for(i=1;i<=n;i++)
		{
			memset(mark,0,sizeof(0));
			if(findpath(i)) res++;
		}
		printf("%d\n",res);
		for(i=1;i<=n;i++)v[i].clear();
	}
	return 0;
}