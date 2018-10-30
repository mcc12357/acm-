//นýมห
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int pie[100005][15],res[100005][15],sign[100005][15];
int main()
{
	int n,tt = -1;
	while(scanf("%d",&n)!=EOF && n)
	{
		int i,t1,t2,j;
		memset(pie,0,sizeof(pie));
		memset(res,0,sizeof(res));
		memset(sign,0,sizeof(sign));
		for(i=0;i<n;i++) 
		{
			scanf("%d %d",&t1,&t2);
			pie[t2][t1]++;
			if(t2>tt) tt = t2;
		}
		int pos = 5;
		sign[0][5] = 1;
		for(i=0;i<tt;i++)
		{
			for(j=0;j<=10;j++)
			{
				if(j>=1 && j<10) 
				{
					if(sign[i][j]&&sign[i][j-1]&&sign[i][j+1])
					{
						res[i+1][j] = max( max(res[i][j-1],res[i][j]),res[i][j+1] ) + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j]&&sign[i][j-1])
					{
						res[i+1][j] = max(res[i][j],res[i][j-1]) + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j]&&sign[i][j+1])
					{
						res[i+1][j] = max(res[i][j],res[i][j+1]) + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j-1]&&sign[i][j+1])
					{
						res[i+1][j] = max(res[i][j+1],res[i][j-1]) + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j])
					{
						res[i+1][j] = res[i][j] + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j-1])
					{
						res[i+1][j] = res[i][j-1] + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j+1])
					{
						res[i+1][j] = res[i][j+1] + pie[i+1][j];
						sign[i+1][j] = 1;
					}
				}
				if(j==0)
				{
					if(sign[i][j] && sign[i][j+1])
					{
						res[i+1][j] = max(res[i][j],res[i][j+1]) + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j])
					{
						res[i+1][j] = res[i][j] + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j+1])
					{
						res[i+1][j] = res[i][j+1] + pie[i+1][j];
						sign[i+1][j] = 1;
					}
				}
				if(j==10)
				{
					if(sign[i][j]&&sign[i][j-1])
					{
						res[i+1][j] = max(res[i][j],res[i][j-1]) + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j])
					{
						res[i+1][j] = res[i][j] + pie[i+1][j];
						sign[i+1][j] = 1;
					}
					else if(sign[i][j-1])
					{
						res[i+1][j] = res[i][j-1] + pie[i+1][j];
						sign[i+1][j] = 1;
					}

				}

			}
		}
		int kk = res[tt][0];
		for(i=0;i<=10;i++) if(kk<res[tt][i]) kk = res[tt][i];
		printf("%d\n",kk);

	}
}