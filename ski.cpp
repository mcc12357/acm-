#include<iostream>
using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int f[100][100],a[100][100],m;
int dp(int x,int y)
{
	if(f[x][y]) return f[x][y];
	f[x][y] = 1;
	if(a[x-1][y]<a[x][y] && x>0) f[x][y]=max(f[x][y],dp(x-1,y)+1);
	if(a[x+1][y]<a[x][y] && x+1<m) f[x][y]=max(f[x][y],dp(x+1,y)+1);
	if(a[x][y-1]<a[x][y] && y>0) f[x][y]=max(f[x][y],dp(x,y-1)+1);
	if(a[x][y+1]<a[x][y] && y+1<m) f[x][y]=max(f[x][y],dp(x,y+1)+1);
	return f[x][y];
}
int main()
{
	int i,j,res;
	scanf("%d",&m);
	for(i=0;i<m;i++)
		for(j=0;j<m;j++) 
		{
			scanf("%d",&a[i][j]);
			f[i][j]=0;
		}
	for(i=0;i<m;i++)
		for(j=0;j<m;j++) f[i][j]=dp(i,j);
	for(i=0;i<m;i++)
		for(j=0;j<m;j++) if(f[i][j]>res) res = f[i][j];
		printf("%d\n",res);




}