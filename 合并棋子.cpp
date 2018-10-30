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
	int n,a[202],res[202][202];
	cin >> n;
	int i,j,k;
	memset(res,0,sizeof(res));
	for(i=0;i<n;i++) cin >> a[i];
	for(i=0;i<n;i++) a[i+n] = a[i];//区间加倍处理出现环问题
	for(i=1;i<=n;i++)//i表示区间长度
		for(j=0;j+i-1<2*n;j++)//j表示起点
		{
			int y = j + i -1;//y表示终点
			res[j][y] = res[j][y-1] + a[y];
			for(k=j;j<=y;j++) res[j][y] = max(res[j][y],res[j][k]+res[k+1][y]);
			
		}
	cout << res[0][2*n-1] << endl;
}