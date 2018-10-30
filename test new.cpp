#include<iostream>
using namespace std;
int f(int x)
{
	int i;
	int sum = 0;
	for(i=2;i<=x;i++) if(x%i==0) sum++;
	return sum;
}
int main()
{
	int max = -1;
	int i;
	for(i=2;i<=20000;i++) 
	{
		int tm = f(i);
		if(max<tm) max = tm;
	}
	printf("%d\n",max);
}