#include<iostream>
using namespace std;
#include<stdio.h>
int pri[100],r,m,k;
void ou(int n)
{
	int i;
	r = 0;
	for(i=2;i*i<=n;i++)//注意不需要循环到n，只需要到根号n
	{
		if(n%i==0)
		{
			pri[r++] = i;
			while(n%i==0) n /= i;
		}
		
	}
	if(n>1) pri[r++] = n;//注意除完根号n以内的素数后最多可能会还有一个素数，此素数可能是大于根号n的
}
int judge(int t)
{
	//ou(m);
	_int64 a = (1 << r),i;
	int res = 0,temp,j;
	for(i=0;i<a;i++)
	{
		temp = 1;
		for(j=0;j<r;j++)
		{
			if((i>>j)&1==1) temp *= (-1) * pri[j];
			if((i>>(j+1))==0) break;
		}
		if(temp!=1) res += t / temp;
	}
	return (t + res);
}
int binarys()
{
	int x = 1,y = 2000000000;
	while(x<y)
	{
		int temp = (x + y) / 2,ss = judge(temp);
		if(k<=ss) y = temp;
		else x = temp + 1;
	}
	return x;

} 
int main()
{
	while(~scanf("%d %d",&m,&k))
	{
		ou(m);
		int res = binarys();
		printf("%d\n",res);
	}
	return 0;
}