#include<iostream>
using namespace std;
#include<stdio.h>
int res[100];
int max(int x,int y)
{
	if(x<y) return y;
	return x; 
}
int main()
{
	int n;
	scanf("%d",&n);
	int k = 0;
	while(n)
	{
		res[k++] = n % 10;
		n /= 10;
	}
	int i;
	int tmax = 0;
	for(i=0;i<k;i++) tmax = max(tmax,res[i]);
	printf("%d\n",tmax);
}