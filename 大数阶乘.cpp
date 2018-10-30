//10000的阶乘结果位数是30000多
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	int a[40000];
	int m;
	scanf("%d",&m);
	int i,j;
	int digital = 0;//阶乘结果当前最后一位有数字的地方
	int carry;//进位
	int temp;
	memset(a,0,sizeof(a));
	a[0] = 1;
	for(i=2;i<=m;i++)
	{
		carry = 0;
		for(j=0;j<=digital;j++)
		{
			temp = i * a[j] + carry;
			a[j] = temp % 10;
			carry = temp / 10;
		}
		while(carry)
		{
			a[++digital] = carry % 10;
			carry /= 10;
		}
	}
	for(i=digital;i>=0;i--) printf("%d",a[i]);
	printf("\n");
	return 0;
}