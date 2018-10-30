#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		int a[21],b[21];
		int i,j,k,sum=9999999;
		for(i=0;i<m;i++) 
		{
			scanf("%d %d",&a[i],&b[i]);
		}
		for(i=0;i<=100;i++)
			for(j=0;j<=100;j++)
			{
				int temp = 0;
				for(k=0;k<m;k++)
				{
					temp += fabs(i-a[k]);
					temp += fabs(j-b[k]);
				}
				sum = min(temp,sum);
			}
			printf("%d\n",sum);
	}
	return 0;
}