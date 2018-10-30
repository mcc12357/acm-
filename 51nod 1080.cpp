#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
bool flag = false;
int n;
bool f(int x)
{
	int y = (int)pow(x,0.5);
	return y*y==x;
}
int main()
{
	scanf("%d",&n);
	int m = n / 2;
	int i;
	for(i=0;i*i<=m;i++)
	{
		int tm = n - i * i;
		if(f(tm))
		{
			flag = true;
			printf("%d %d\n",i,(int)pow(tm,0.5));
		}
	}
	if(!flag) printf("No Solution\n"); 
}