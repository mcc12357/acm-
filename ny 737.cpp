//超时
#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
/*int min(int x,int y)
{
	if(x<y) return x;
	else return y;
}*/
_int64 res[405][405];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,k;
		if(n==1) 
		{	
			scanf("%d",&k);
			printf("0\n");
		}
		else
		{
			_int64 a[405];
			_int64 kk = 1 << 63;
			memset(res,0,sizeof(res));
			for(i=0;i<n-1;i++) {scanf("%I64d",&a[i]);a[i+n] = a[i];}
			scanf("%I64d",&a[n-1]);
			for(i=1;i<2*n-1;i++) a[i] += a[i-1];
			for(i=1;i<n;i++)//i表示区间长度,n个点区间长度最多为n-1
			{
				for(j=0;j+i<2*n-1;j++)//j表示区间起点
				{
					int r = i + j;//r表示区间终点
					if(j==0 && r<n)
					{
						res[j][r] = res[j][r-1] +res[r][r] + a[r];
						for(k=j;k<=r;k++)
						{
							if(res[j][r]>res[j][k] + res[k+1][r] + a[r])
								res[j][r] = res[j][k] + res[k+1][r] + a[r];
						}
					}
					else 
					{
						res[j][r] = res[j][r-1] + res[r][r] + a[r] - a[j-1];
						for(k=j;k<=r;k++)
						{
							if(res[j][r]>res[j][k] + res[k+1][r] + a[r] - a[j-1])
								res[j][r] = res[j][k] + res[k+1][r] + a[r] - a[j-1];
						}
					}
				}
			}
			kk = res[0][n-1];
			for(i=0;i<n;i++) if(kk>res[i][i+n-1]) kk = res[i][i+n-1];
			printf("%I64d\n",kk);
		}
	}	
	return 0;
}
