#include<iostream>
using namespace std;
#include<string.h>
#include<math.h>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int n;
	cin >> n;
	int i,j,a[50001][2],res[50001][2];
	memset(res,0,sizeof(res));
	for(i=0;i<n;i++)
	{
		cin >> a[i][0];
		a[i][1] = 1;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<=1;j++)
		{
			res[i][j] = max(res[i-1][0]+fabs(a[i-1][0]-a[i][j]),res[i-1][1]+fabs(a[i-1][1]-a[i][j]));
		}
	}
	int kk = max(res[n-1][0],res[n-1][1]);
	cout << kk << endl;
}