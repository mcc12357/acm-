#include<stdio.h>
#define sum(x,y,z) \
	x = 3;\
	y = 4;\
	z = 5;\
	int sum = x + y + z;\
	printf("%d\n",sum);
int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	sum(x,y,z);
}