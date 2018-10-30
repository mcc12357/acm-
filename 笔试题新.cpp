#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int m,n;//m行n列的矩阵
int a[100][100];//a保存矩阵结果
bool isres;//是否存在解
int res;//当前是第几组解

//找到解后打印矩阵的函数
void print()
{
	int sum = 0;
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++) sum += a[i][j];
	if(sum==0) return ;
	printf("result %d is :\n",res);
	res++;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	isres = true;
}

//判断位置(x,y)处的数是否满足和谐矩阵的定义
bool judge(int x,int y)
{
	int sum = 0;
	sum = a[x][y] + a[x-1][y] + a[x+1][y] + a[x][y-1] + a[x][y+1];
	if(sum % 2) return false;
	return true;
}

//当前在(x,y)处放上数值k继续往下递归
void dfs(int x,int y,int k)
{
	a[x][y] = k;
	if(x>1 && !judge(x-1,y)) return ;//如果上一行即(x-1,y)处已经不满足和谐矩阵定义，提前结束递归
	if(x==m)//考虑最后一行的情况
	{
		if(y>1 && !judge(x,y-1)) return ;//如果前一列即(x,y-1)处已经不满足和谐矩阵定义，提前结束递归
		if(y==n)//已经到最后一个数，递归结束，判断结果如果满足就打印
		{
			if(!judge(x,y)) return ;
			print();
		}
		else//继续递归
		{
			dfs(x,y+1,0);
			dfs(x,y+1,1);
		}
		return ;
	}
	else//不是最后一行的结果
	{
		if(y==n)//到达最后一列，递归从下一行第一个开始
		{
			dfs(x+1,1,0);
			dfs(x+1,1,1);
		}
		else//否则从本行下一列开始
		{
			dfs(x,y+1,0);
			dfs(x,y+1,1);
		}
	}
}
int main()
{
	while(~scanf("%d %d",&m,&n))
	{
		memset(a,0,sizeof(a));//初始化a矩阵为全0,行数1-m,列数1-n为和谐矩阵，0行0列以及m+1行,n+1列为加的一圈0
		isres = false;//初始化为假，说明还未找到解
		res = 1;//初始化为1，说明第一组解
		dfs(1,1,0);//第一个位置(1,1)放入0开始递归
		dfs(1,1,1);//第一个位置(1,1)放入1开始递归
		if(!isres) printf("no result!\n");//未找到解输出无解
	}
}