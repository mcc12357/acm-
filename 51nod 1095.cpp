#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
typedef _int64 ll;
bool judge(int x)
{
	if(x==1) return true;
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
struct cmp
{
	bool operator () (char const* x,char const* y)
	{
		return strcmp(x,y)<0;
	}
};
map<char*,int,cmp> s;
map<char*,int,cmp>::iterator it;
map<char*,int,cmp> t;
map<char*,int,cmp>::iterator ite;
int main()
{
	int i;
	int n,m;
	scanf("%d",&n);
	int j;
	for(i=0;i<n;i++)
	{
		char* a;
		char b[12];
		//cin>>a;
		cin>>b;
		a = b;
		it = s.find(a);
		int len = strlen(a);
		if(it==s.end())
		{
			s[a] = 1;
		}
		else
		{
			s[a]++;
		}
		sort(a,a+len);
		ite = t.find(a);
		if(ite==t.end())
		{
			t[a] = 1;
		}
		else
		{
			t[a]++;
		}
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		char* a;
		char b[12];
		cin>>b;
		a = b;
		int num1,num2;
		it = s.find(a);
		if(it==s.end())
		{
			num1 = 0;
		}
		else num1 = it->second;
		int len = strlen(a);
		sort(a,a+len);
		ite = t.find(a);
		if(ite==t.end())
		{
			num2 = 0;
		}
		else num2 = ite->second;
		printf("%d\n",num2-num1);
	}
	/*int num = 0;
	FILE *fp;
	fp = fopen("C:\\test.txt","w");
	for(i=1;;i++)
	{
		if(num==26) break;
		if(judge(i)) 
		{
			fprintf(fp,"%d,",i);
			num++;
		}
	}*/
}