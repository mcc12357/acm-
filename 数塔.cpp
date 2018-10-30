#include<iostream>
using namespace std;
int max(int m,int n)
{
	if(m>=n) return m;
	else return n;
}
int main()
{
	int a[100][100],b[100][100];
	int i,j;
	int m;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=i;j++) scanf("%d",&a[i][j]);
	}
	for(i=1;i<=m;i++) b[m][i] = a[m][i];
	for(i=m;i>=1;i--)
	{
		for(j=1;j<=m;j++) b[i-1][j] = max(b[i][j],b[i][j+1]) + a[i-1][j]; 
	}
	//printf("%d\n",b[1][1]);//输出最大数值
	/*输出所得最大数值的路径
	int res1,res2;
	res1 = b[1][1];
	for(i=2;i<m;i++)
	{
		res2 = b[i][1];
		for(j=1;j<=i;j++) 
		{
			res2 = max(res2,b[i][j]);
		}
		printf("%d\n",res1-res2);
		res1 = res2;
	}
	for(i=1;i<=m;i++) if(b[m-1][i]==res1) break;
	printf("%d\n",res1-max(b[m][i],b[m][i+1]));
	printf("%d\n",max(b[m][i],b[m][i+1]));
	*/

}