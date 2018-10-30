#include<iostream>
using namespace std;
void tower(int n,char from,char to,char help)
{
	if(n==1) 
	{
		printf("%s %c %s %c\n","move disk 1 from",from,"to",to);
		return ;
	}
	tower(n-1,from,help,to);
	printf("%s %d %s %c %s %c\n","move disk",n,"from",from,"to",to);
	tower(n-1,help,to,from);
}
int main()
{
	tower(4,'A','C','B');`
}