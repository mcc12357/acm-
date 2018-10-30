/*
刚开始循环顺序搞反了，先循环的起点，再循环的区间长度。这样的结果是虽然res[i][j]表示以i为起点j为终点这段区间
所有最大匹配括号数，但是当i第一重循环结束后从等于0到等于1后，再没有更新的机会了，所以结果完全不对了。注：区间dp
不可能以起点，终点2重循环，否则当起点++后便不会有更新机会。所以应该外层区间长度循环，内层起点循环！
*/
#include<iostream>
#include<string.h>
using namespace std;
char a[101];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
bool f(int i,int y)
{
	if(a[i]=='(' && a[y]==')') return true;
	if(a[i]=='[' && a[y]==']') return true;
	return false;
}
int main()
{
	int i,j,k,len;
	int res[101][101];
	memset(res,0,sizeof(res));
	scanf("%s",a);
	len = strlen(a);
	for(i=1;i<=len;i++)//i表示区间长度
		for(j=0;i+j-1<len;j++)//j表示起点坐标
		{
			int y = j + i - 1;//y表示终点坐标
			if(f(j,y)) res[j][y] = res[j+1][y-1] + 1;
			for(k=j;k<=y;k++)
			{
				res[j][y] = max(res[j][y],res[j][k]+res[k+1][y]);
			}
		}
		cout << res[0][len-1] << endl;
}