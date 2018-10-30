//测试数据全没问题，但是没过。
#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m,n,a[101][101],b[101],res[101];
		cin >> m >> n;
		int i,j,k,p = -1 << 30;
		for(i=0;i<m;i++) for(j=0;j<n;j++) cin >> a[i][j];
		p = a[0][0];
		for(i=0;i<m;i++)
		{
			res[0] = a[i][0];
			for(j=1;j<n;j++)
			{
				if(res[j-1]>0) res[j] = res[j-1] + a[i][j];
				else res[j] = res[j-1];
			}
			for(j=0;j<n;j++) if(res[j]>p) p = res[j];
		}//考虑所有一排的情况，因为下面没有考虑
		for(i=1;i<m;i++)
			for(j=0;j<n;j++) a[i][j] += a[i-1][j];

		for(i=0;i<m;i++)
		{
			
			for(j=i+1;j<m;j++)
			{
				memset(b,0,sizeof(b));
				for(k=0;k<n;k++)
				{
					if(i>=1) b[k] = a[j][k] - a[i-1][k];
					else b[k] = a[j][k];
				}
				res[0] = b[0];
				for(k=1;k<n;k++)
				{
					if(res[k-1]>0) res[k] = res[k-1] + b[k];
					else res[k] = b[k];
				}
				int temp;
				temp = res[0];
				for(k=1;k<n;k++) if(temp < res[k]) temp = res[k];
				if(temp > p) p = temp;
			}
		}
		cout << p << endl;
	}
}