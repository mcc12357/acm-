#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<set>
#include<map>
#define maxn 1000010
char ss[maxn];
int a[maxn],sum[maxn];
set<int> s;
set<int>::iterator st;
map<int,int> m1;
map<int,int> m2;
map<int,int>::iterator mt;
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	scanf("%s",ss);
	int i;
	int n = strlen(ss);
	for(i=0;i<n;i++)
	{
		if(ss[i]=='0') a[i] = -1;
		else a[i] = 1;
	}
	sum[0] = a[0];
	for(i=1;i<n;i++) sum[i] = sum[i-1] + a[i];
	for(i=0;i<n;i++)
	{
		st = s.find(sum[i]);
		if(st==s.end())
		{
			m1[sum[i]] = i;
			m2[sum[i]] = i;
			s.insert(sum[i]);
		}
		else
		{
			m2[sum[i]] = i;
		}
	}
	int res = 0;
	for(st=s.begin();st!=s.end();st++)
	{
		res = max(res,m2[*st]-m1[*st]);
	}
	if(res) printf("%d\n",res);
	else
	{
		bool flag = false;
		for(i=0;i<n;i++) 
		{
			if(!sum[i]) 
			{
				flag = true;
				break;
			}
		}
		if(flag) printf("2\n");
		else printf("0\n");
	}
}