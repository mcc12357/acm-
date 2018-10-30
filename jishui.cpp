#include<iostream>
using namespace std;
char a[100][100];
int p,q;
void dfs(int m,int n)
{
	if(a[m][n]=='.') return;
	else a[m][n]='.';
	int dx[3]={-1,0,1},dy[3]={-1,0,1};
	int nx,ny,i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			if(i==1&&j==1) continue;
			nx = m + dx[i];
			ny = n + dy[j];
			if(nx>=0 && nx<p && ny>=0 && ny<q && a[nx][ny]=='w')
			{
				dfs(nx,ny);
			}
		}

}
int main()
{
	int i,j,ans=0;
	scanf("%d %d",&p,&q);
	for(i=0;i<p;i++) for(j=0;j<q;j++) scanf("%c",&a[i][j]);
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
		{
			if(a[i][j]=='w') 
			{
				dfs(i,j);
				ans++;
			}
		}
	printf("%d\n",ans);
}