#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		int i,a[305],b[305];
		int num1 = 0,num2 = 0;
		bool flag = false;
		priority_queue<int> q;
		for(i=0;i<m;i++) 
		{
			scanf("%d",&a[i]);
			num1 += a[i];
			q.push(a[i]);
			if(a[i]>n) flag = true;
		}
		for(i=0;i<n;i++) 
		{
			scanf("%d",&b[i]);
			num2 += b[i];
			if(b[i]>m) flag = true;
		}
		if(num1!=num2 || flag)
		{
			printf("Terrible\n");
		}
		else
		{
			while(!q.empty())
			{
				int tm = q.top();
				q.pop();
				sort(b,b+n,cmp);
				for(i=0;i<tm;i++) 
				{
					if(b[i]==0)
					{
						flag = true;
						break;
					}
					else b[i] -= 1;
				}
				if(flag) break;
			}
			if(flag) printf("Terrible\n");
			else printf("Not Sure\n");
		}
	}
	return 0;
}