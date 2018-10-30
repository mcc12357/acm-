#include<iostream>
using namespace std;
#include<stdio.h>
int a[7];
bool flag;
int sum;
int val;
int num = 0;
void dfs(int value,int index)
{
	if(flag) return;
	if(value==val) 
	{
		flag = true;
		return;
	}
	int i;
	for(i=index;i>0;i--)
	{
		if(a[i])
		{
			if(i+value<=val)
			{
				a[i]--;
				dfs(i+value,i);
				if(flag) return ;
				//a[i]++;
			}
		}
	}
}
int main()
{
	while(1)
	{
		int i;
		sum = 0;
		num++;
		for(i=1;i<=6;i++) {scanf("%d",&a[i]);sum += a[i] * i;}
		val = sum / 2;
		if(!a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6]) break;
		flag = false;
		if(sum%2)
		{
			printf("Collection #%d:\n",num);
			printf("Can't be divided.\n\n");
		}
		else
		{
			dfs(0,6);
			if(flag)
			{
				printf("Collection #%d:\n",num);
				printf("Can be divided.\n\n");
			}
			else
			{
				printf("Collection #%d:\n",num);
				printf("Can't be divided.\n\n");
			}
		}
	}
}