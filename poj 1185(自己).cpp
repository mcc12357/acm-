#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int map[105][15];
int tm[10];
int sum = 0;
int dp[105][70][70];
int state[70];
int p = 0;
void f(int a[])
{
	int i = 0;
	for(i=0;i<10;i++) if(a[i]) state[p] += (1<<(10-i-1));
	p++;
}
void valid(int k,int t)//µÚkÎ»·Åt
{
	tm[k] = t;
	if(k==9)
	{
		if(t==0) {sum++;f(tm);}
		else
		{
			if(tm[7]==0 && tm[8]==0) {sum++;f(tm);}
		}
		return ;
	}
	valid(k+1,0);
	if(tm[k-1]==0 && tm[k]==0) valid(k+1,1);

}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int i,j,k;
	char c;
	for(i=0;i<m;i++) for(j=0;j<n;j++) 
	{
		cin>>c;
		if(c=='P') map[i][j] = 0;
		if(c=='H') map[i][j] = 1;
	}
	valid(0,0);
	valid(0,1);
	//printf("%d\n",sum);
	for(i=0;i<p;i++) 
	{
		int tt = h()
		if()
		dp[0][0][state[i]]
	}
	for(i=0;i<m;i++)
	{
		
	}


}