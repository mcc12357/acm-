#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
int isoriginal[200];
float a[15];
int used[15];
vector<char> v;
bool flag;
float res;
void print()
{
	int i;
	/*for(i=0;i<v.size();i++)
	{
		if(v[i]=='+'||v[i]=='-'||v[i]=='*'||v[i]=='/')
		{
			printf("%c ",v[i]);
		}
		else
		{
			if(!isoriginal[v[i]]) continue;
			else
			{
				isoriginal[v[i]]--;
				printf("%d ",v[i]);
			}
		}
	}
	printf("\n");*/
	//int i;
	for(i=0;i<v.size();i++) 
	{
		if(v[i]=='+'||v[i]=='-'||v[i]=='*'||v[i]=='/')
		{
			printf("%c ",v[i]);
		}
		else printf("%d ",v[i]);
	}
	printf("\n");
}
float abs(float x)
{
	if(x>0) return x;
	return -x;
}
void f(int x)
{
	int i;
	for(i=1;i<=x;i++) v.pop_back();
}
void dfs(int top,int num)
{
	if(flag) return;
	if(num==1)
	{
		if(abs(res-24)<0.0001) flag = true;
		return;
	}
	int i,j;
	for(i=0;i<top-1;i++)
	{
		if(used[i]) continue;
		used[i] = 1;
		for(j=i+1;j<top;j++)
		{
			if(used[j]) continue;
			int kk = 1,flag1 = 0,flag2 = 0;
			used[j] = 1;
			res = a[i] + a[j];
			if(res>=0)
			{
				a[top] = res;
				if(isoriginal[(int)a[i]]>0 && a[i]>=0) {v.push_back(a[i]);kk++;isoriginal[(int)a[i]]--;flag1 = 1;}
				if(isoriginal[(int)a[j]]>0 && a[i]>=0) {v.push_back(a[j]);kk++;isoriginal[(int)a[j]]--;flag2 = 1;}
				v.push_back('+');
				dfs(top+1,num-1);
				if(flag) return ;
				f(kk);
				if(flag1) isoriginal[(int)a[i]]++;
				if(flag2) isoriginal[(int)a[j]]++;
			}
			kk = 1;
			res = a[i] - a[j];
			if(res>=0)
			{
				a[top] = res;
				if(isoriginal[(int)a[i]]>0 && a[i]>=0) {v.push_back(a[i]);kk++;isoriginal[(int)a[i]]--;flag1 = 1;}
				if(isoriginal[(int)a[j]]>0 && a[j]>=0) {v.push_back(a[j]);kk++;isoriginal[(int)a[j]]--;flag2 = 1;}
				v.push_back('-');
				dfs(top+1,num-1);
				if(flag) return;
				f(kk);
				if(flag1) isoriginal[(int)a[i]]++;
				if(flag2) isoriginal[(int)a[j]]++;
			}
			kk = 1;
			res = a[j] - a[i];
			if(res>=0)
			{
				a[top] = res;
				if(isoriginal[(int)a[j]]>0 && a[j]>=0) {v.push_back(a[j]);kk++;isoriginal[(int)a[j]]--;flag2 = 1;}
				if(isoriginal[(int)a[i]]>0 && a[i]>=0) {v.push_back(a[i]);kk++;isoriginal[(int)a[i]]--;flag1 = 1;}
				v.push_back('-');
				dfs(top+1,num-1);
				if(flag) return;
				f(kk);
				if(flag1) isoriginal[(int)a[i]]++;
				if(flag2) isoriginal[(int)a[j]]++;
			}
			kk = 1;
			res = a[i] * a[j];
			if(res>=0)
			{
				a[top] = res;
				if(isoriginal[(int)a[i]]>0 && a[i]>=0) {v.push_back(a[i]);kk++;isoriginal[(int)a[i]]--;flag1 = 1;}
				if(isoriginal[(int)a[j]]>0 && a[j]>=0) {v.push_back(a[j]);kk++;isoriginal[(int)a[j]]--;flag2 = 1;}
				v.push_back('*');
				dfs(top+1,num-1);
				if(flag) return;
				f(kk);
				if(flag1) isoriginal[(int)a[i]]++;
				if(flag2) isoriginal[(int)a[j]]++;
			}
			kk = 1;
			if(a[i])
			{
				res = a[j] / a[i];
				if(res>=0)
				{
					a[top] = res;
					if(isoriginal[(int)a[j]]>0 && a[j]>=0) {v.push_back(a[j]);kk++;isoriginal[(int)a[j]]--;flag2 = 1;}
					if(isoriginal[(int)a[i]]>0 && a[i]>=0) {v.push_back(a[i]);kk++;isoriginal[(int)a[i]]--;flag1 = 1;}
					v.push_back('/');
					dfs(top+1,num-1);
					if(flag) return;
					f(kk);
					if(flag1) isoriginal[(int)a[i]]++;
					if(flag2) isoriginal[(int)a[j]]++;
				}
			}
			kk = 1;
			if(a[j])
			{
				res = a[i] / a[j];
				if(res>=0)
				{
					a[top] = res;
					if(isoriginal[(int)a[i]]>0 && a[i]>=0) {v.push_back(a[i]);kk++;isoriginal[(int)a[i]]--;flag1 = 1;}
					if(isoriginal[(int)a[j]]>0 && a[j]>=0) {v.push_back(a[j]);kk++;isoriginal[(int)a[j]]--;flag2 = 1;}
					v.push_back('/');
					dfs(top+1,num-1);
					if(flag) return ;
					f(kk);
					if(flag1) isoriginal[(int)a[i]]++;
					if(flag2) isoriginal[(int)a[j]]++;
				}
			}
			used[j] = 0;
		}
		used[i] = 0;
	}
}
int main()
{
	//int t;
	while(1)
	{
		printf("please enter 4 number:\n");
		v.clear();
		memset(a,0,sizeof(a));
		memset(used,0,sizeof(used));
		memset(isoriginal,0,sizeof(isoriginal));
		int i;
		for(i=0;i<4;i++) {scanf("%f",&a[i]);isoriginal[(int)a[i]]++;}
		flag = false;
		//printf("%d %d %d\n",isoriginal[2],isoriginal[4],isoriginal[6]);
		dfs(4,4);
		//printf("%d %d %d\n",isoriginal[2],isoriginal[4],isoriginal[6]);
		if(flag) print();
		else printf("no answer!\n");
	}
	return 0;
}
  
