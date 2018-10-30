//不对
#include<iostream>
using namespace std;
#include<string.h>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int n;
	cin >> n;
	int i,j,k;
	int a[205];
	int kk = 0;
	int num[205][205],res[205][205];
	memset(num,0,sizeof(num));
	memset(res,0,sizeof(res));
	for(i=0;i<n-1;i++) {cin >> a[i];a[i+n] = a[i];}
	cin >> a[n-1];
	for(i=1;i<2*n-1;i++) a[i] += a[i-1];
	for(i=1;i<n;i++)//i表示区间长度,n个点区间长度最多为n-1
	{
		for(j=0;j<2*n-1;j++)//j表示区间起点
		{
			int r = i + j;//r表示区间终点
			if(j==0)
			{
				for(k=j;k<r;k++)
				{
					res[k][k] = 0;
					//res[k+1][k+1] = 0;
					res[j][r] = max(res[j][r],res[j][k] + res[k+1][r] + a[r]);
					if(res[j][r]>kk) kk = res[j][r];
				}
			}
			else 
			{
				for(k=j;k<r;k++)
				{
					res[k][k] = 0;
					//res[k+1][k+1] = 0;
					res[j][r] = max(res[j][r],res[j][k] + res[k+1][r] + a[r] - a[j-1]);
					if(res[j][r]>kk) kk = res[j][r];
				}
			}
		}
	}
	cout << kk << endl;
		
}
