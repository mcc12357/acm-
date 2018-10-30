#include<stdio.h>
int d[10];
int x,y;
int main()
{
	int i,j;
	int tmp = 1;
	for(i=0;i<10;i++)
	{
		d[i] = tmp;
		tmp *= 10;
	}
	x = 4;
	y = 6;
	int n,m;
	for(i=1;i<=10;i++)
	{
		bool res = false;
		for(j=0;j<d[i];j++)
		{
			n = x + y * d[i+1] + 10 * j;
			m = y + 10 * x + 100 * j;
			if(n==4 * m) 
			{
				res = true;
				break;
			}
		}
		if(res==true) break;
	}
	printf("%d\n",n);
}