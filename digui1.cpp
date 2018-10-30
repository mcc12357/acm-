#include<iostream>
using namespace std;
void hanio(int n,char origin,char temp,char res)
{
	if(n==1)
	{
		printf("Move %d %c->%c\n",n,temp,res);
	}
	else
	{
		hanio(n-1,origin,res,temp);
		printf("Move %d %c->%c\n",n,origin,res);
		hanio(n-1,temp,origin,res);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	hanio(t,'A','B','C');
	return 0;
}