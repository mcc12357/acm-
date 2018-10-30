#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	int a[20][20];
	while(t--)
	{
		int n;
		scanf("%d",&n);	
		int ans = n * n;
		memset(a,0,sizeof(a));
		int mid = n / 2 + 1;
		a[1][mid] = 1;
		a[n][mid] = ans;
		//a[n][mid+1] = 2;
		int p = 2,i = n,j = mid + 1;
		while(p<ans)
		{
			while(i>0 && j<=n && a[i][j]==0)
			{
				a[i][j] = p;
				p++;
				i -= 1;
				j += 1;
			}
			if(j==n+1 && i!=0) j = 1;
			else if(i==0 && j!=n+1) i = n;
			else if(i==0 && j==n+1) {i += 2;j--;}
			else {i += 2;j--;}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) printf("%4d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}