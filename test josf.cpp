#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int change(char x)
{
	if(x=='e') return 1;
	else if(x=='u') return 2;
	else return 3;
}
int is[12];
int main()
{
	int t;
	while(t--)
	{
		memset(is,0,sizeof(is));
		char firstleft[6],firstright[6],firstres[5];
		char secondleft[6],secondright[6],secondres[5];
		char thirdleft[6],thirdright[6],thirdres[5];
		int fisres = change(firstres[0]);
		int secres = change(secondres[0]);
		int thires = change(thirdres[0]);
		int len1 = strlen(firstleft);
		int len2 = strlen(secondleft);
		int len3 = strlen(thirdleft);
		int i;


	}
}