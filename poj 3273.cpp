#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
const int inf = 10005;
int n,m;
int a[100005];
bool f(int x)
{
	int i;
	int num = 0;
	int sum = 0;
	for(i=0;i<n;i++)
	{
		if(a[i]>x) return true;
		if(sum+a[i]>x)
		{
			num++;
			sum = a[i];
		}
		//if(i==n-1 && num==m && sum+a[i]>x) return true;
		else sum += a[i];
		if(num>=m) return true;
	}
	return false;
}
int main()
{
	//FILE *fp;
	//fp = fopen("C:\\1.txt","w");
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	int lb = 0,ub = inf;
	while(ub-lb>1)
	{
		int mid = (ub + lb) / 2;
		if(f(mid)) lb = mid;
		else ub = mid;
	}
	if(!f(lb)) printf("%d\n",lb);
	else printf("%d\n",ub);
	//if(fp!=NULL) fprintf(fp,"%d\n",lb);
	//fclose(fp);
}
/*
13 9
10
10
3
10
4
1
9
6
8
8
10
5
6
*/