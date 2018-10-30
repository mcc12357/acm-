#include<iostream>
using namespace std;
#include<string.h>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int n,m,a[21][21],res[21][21];
int dp(int x,int y)
{
	if(x==0 && y==0) return a[0][0];
	if(res[x][y]) return res[x][y];
	if(x==0 && y) res[x][y] = res[x][y-1] + a[x][y];
	if(x && y==0) res[x][y] = res[x-1][y] + a[x][y];
	if(x && y && res[x][y]==0) res[x][y] = max(dp(x,y-1),dp(x-1,y)) + a[x][y];
	return res[x][y];
}
int main()
{
	int i,j;
	memset(res,0,sizeof(res));
	cin >> n >> m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++) cin >> a[i][j];
	res[n-1][m-1] = dp(n-1,m-1) + a[0][0];
	cout << res[n-1][m-1] << endl;
	return 0;
}