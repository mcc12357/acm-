#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
int visited[12];	
int b[12];
int c[12];
int k;
int res;
int abs(int x)
{
	if(x>0) return x;
	return -x;
}
/*void dfs(int x)
{
	int i;
	if(x==k)
	{
		int res1 = 0,res2 = 0;
		int kk = 1;
		for(i=k/2-1;i>=0;i--) 
		{
			res1 += kk * c[i];
			kk *= 10;
		}
		kk = 1;
		for(i=k-1;i>=k/2;i--)
		{
			res2 += kk * c[i];
			kk *= 10;
		}
		
		int tm = abs(res1-res2);
		if(tm<res) 
		{
			//printf("%d %d\n",res1,res2);
			res = tm;
		}
		return ;
	}
	for(i=0;i<k;i++)
	{
		if(x==0 && b[i]==0) continue;
		if(x==k/2 && b[i]==0) continue;
		if(!visited[i])
		{
			visited[i] = 1;
			c[x] = b[i];
			dfs(x+1);
			visited[i] = 0;
		}
	}
}*/
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		int i;
		res = 100000;
		memset(visited,0,sizeof(visited));
		//memset(c,0,sizeof(c));
		char a[25];
		k = 0;
		for(i=0;i<25;i++) a[i] = ' ';
		gets(a);
		for(i=0;i<25;i++)
		{
			if(a[i]==' ' && a[i+1]==' ') break;
			if(a[i]==' ') continue;
			b[k++] = a[i]-'0';
		}
		k--;
		//printf("%d\n",k);
		//for(i=0;i<k;i++) printf("%d\n",b[i]);
		//dfs(0);
		do
		{
			int res1 = 0,res2 = 0;
			int kk = 1;
			if(b[k/2]==0 || b[0]==0) continue;
			for(i=k/2-1;i>=0;i--) 
			{
				res1 += kk * b[i];
				kk *= 10;
			}
			kk = 1;
			for(i=k-1;i>=k/2;i--)
			{
				res2 += kk * b[i];
				kk *= 10;
			}
			
			int tm = abs(res1-res2);
			if(tm<res) 
			{
				//printf("%d %d\n",res1,res2);
				res = tm;
			}
		}
		while(next_permutation(b,b+k));
		printf("%d\n",res);
	}
}