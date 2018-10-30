#include<iostream>
using namespace std;
int f(int m)
{
	int i,sum=1;
	for(i=1;i<=m;i++) sum *= i;
	return sum;
}
int main()
{
	int i,m,n,j;
	for(i=1;i<=4000000;i++)
	{
		n = 0;
		j = i;
		while(j)
		{
			m = j % 10;
			n += f(m);
			j /= 10;
		}
		if(n == i) printf("%d\n",i);
	}
}