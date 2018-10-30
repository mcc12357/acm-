#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#define maxn 100010
int n,k,a,b;
char res[maxn];
int main()
{
	scanf("%d %d %d %d",&n,&k,&a,&b);
	int flip = 0;
	int i = 0;
	int j;
	if(a<b) 
	{
		swap(a,b);
		flip++;
	}
	/*for(j=1;j<=k;j++) 
	{
		if(flip%2==0) res[i++] = 'G';
		else res[i++] = 'B';
	}
	if(flip%2==0)
	{
		res[i++] = 'B';
	}*/
	while(1)
	{
		if(a<=k && b<=k) break;
		if(a==0 || b==0) break;
		if(a<b) 
		{
			swap(a,b);
			flip++;
			for(j=1;j<=k-1;j++) 
			{
				if(flip%2==0) res[i++] = 'G';
				else res[i++] = 'B';
			}
			if(flip%2==0)
			{
				res[i++] = 'B';
				
			}
			else
			{
				res[i++] = 'G';
			}
			a -= k-1;
			b -= 1;
		}
		else
		{
			for(j=1;j<=k;j++)
			{
				if(flip%2==0) res[i++] = 'G';
				else res[i++] = 'B';
			}
			if(flip%2==0)
			{
				res[i++] = 'B';
				
			}
			else
			{
				res[i++] = 'G';
			}
			a -= k;
			b -= 1;
		}
	}
	if(a>k || b>k) printf("NO\n");
	else
	{
		for(j=1;j<=a;j++)
		{
			if(flip%2==0) res[i++] = 'G';
			else res[i++] = 'B';
		}
		for(j=1;j<=b;j++) 
		{
			if(flip%2==0) res[i++] = 'B';
			else res[i++] = 'G';
		}
		for(j=0;j<i;j++) printf("%c",res[j]);
		printf("\n");
	}
}