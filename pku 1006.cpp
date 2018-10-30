//中国剩余定理
#include<iostream>
using namespace std;
#include<stdio.h>
void exgcd(int a,int b,int &x,int &y)
{
	if(b!=0)
	{
		int x1,y1;
		exgcd(b,a%b,x1,y1);
		if(a*b < 0)
		{ 
            x = - y1;  
            y = a/b*y1 - x1;  
        }
		else
		{ 
            x = y1;  
            y = x1 - a/b* y1;  
        }  
	}
	else
	{
		x = 1;
		y = 0;
	}
}
int cal(int a[],int m[],int k)
{
	int temp;
	int mm = 1;
	int result = 0;
	int i;
	for(i=0;i<k;i++) mm *= m[i];
	for(i=0;i<k;i++)
	{
		int x,y;
		exgcd(mm/m[i],-m[i],x,y);
		temp = m[i] * y + 1;
		result += temp * a[i];
	}
	return (result % mm + mm) % mm;

}
int main()
{
	int a[3],b[3],date;
	b[0] = 23;
	b[1] = 28;
	b[2] = 33;
	int count = 1;
	while(~scanf("%d %d %d %d",&a[0],&a[1],&a[2],&date) && a[0]!=-1)
	{
		/*a[0] = a[0] % b[0];
		a[1] = a[1] % b[1];
		a[2] = a[2] % b[2];*/
		int res = (cal(a,b,3) - date + 21252) % 21252;
		if(res==0) res = 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",count,res);
		count++;
	}
}