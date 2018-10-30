//‘À––≥¨ ±
#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#include<queue>
int a[100001],b[100001],res[100001],flag[100001],c[100001];
int n,num;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&num);
		n;
		int i,j;
		for(i=1;i<n;i++) scanf("%d %d",&a[i],&b[i]);
		memset(flag,0,sizeof(flag));
		memset(res,0,sizeof(res));
		memset(c,0,sizeof(c));
		res[num] = -1;
		queue<int> que;
		que.push(num);
		for(i=1;i<n;i++) 
		{
			c[a[i]]++;
			c[b[i]]++;
		}
		while(que.size())
		{
			int temp = que.front();
			que.pop();
			for(i=1;i<n;i++)
			{
				if(a[i]==temp && flag[temp]==0)
				{
					if(flag[b[i]]==0)
					{		
						res[b[i]] = temp;
						if(c[b[i]]!=1) que.push(b[i]);
					}
				}
				if(b[i]==temp && flag[temp]==0)
				{
					if(flag[a[i]]==0)
					{
						res[a[i]] = temp;
						if(c[a[i]]!=1)que.push(a[i]);
					}
				}
			}
			flag[temp] = 1;
		}
		//f(num);
		for(i=1;i<=n-1;i++) printf("%d ",res[i]);
		printf("%d\n",res[n]);
	}
	//getchar();
	return 0;
}