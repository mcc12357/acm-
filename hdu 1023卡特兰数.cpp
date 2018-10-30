//做大数问题时数组每一位里不一定只保存一位，可以保存多位，如a[n][max-1]表示为n时的结果，a[n][1]可以保存4位结果，以此类推
#include<iostream>
using namespace std;
#include<string.h>
const int MAX = 100;
const int BASE = 10000;
void multiply(int a[],int max,int b)//大数乘法
{
	int i,array = 0;
	for(i=max-1;i>=0;i--)
	{
		array += b * a[i];//b*a[i]最多是4位数，所以BASE必须至少1e5,否则得不到当前位正确结果
		a[i] = array % BASE;
		array /= BASE;
	}
}
void divide(int a[],int max,int b)//大数除法
{
	int i,div = 0;
	for(i=0;i<max;i++)
	{
		div = div * BASE + a[i];
		a[i] = div / b;
		div %= b;
	}
}
int main()
{
	int a[101][MAX],i,j,n;
	memset(a[1],0,MAX*sizeof(int));
	for(i=2,a[1][MAX-1]=1;i<101;i++)
	{
		memcpy(a[i],a[i-1],MAX*sizeof(int));
		multiply(a[i],MAX,4 * i - 2);
		divide(a[i],MAX,i + 1);
	}
	while(cin>>n)
	{
		for(i=0;i<MAX && a[n][i]==0;i++);//去掉数组前为0的数字
		cout << a[n][i++];//输出第一个非0数
		for(;i<MAX;i++)
			printf("%04d",a[n][i]);
		cout << endl;
	}
	return 0;
}