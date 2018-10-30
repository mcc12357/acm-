#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
char dic[30] = {'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
int main()
{
	char a[205];
	while(gets(a))
	{
		if(a[0]=='S' && a[1]=='T' && a[2]=='A' && a[3]=='R' && a[4]=='T' && a[5]=='\0') continue;
		if(a[0]=='E' && a[1]=='N' && a[2]=='D' && a[3]=='\0') continue;
		if(a[0]=='E'&&a[1]=='N'&&a[2]=='D'&&a[3]=='O'&&a[4]=='F'&&a[5]=='I'&&a[6]=='N'&&a[7]=='P'&&a[8]=='U'&&a[9]=='T') break;
		int m = strlen(a);
		int i;
		for(i=0;i<m;i++)
		{
			if(a[i]>='A' && a[i]<='Z') printf("%c",dic[a[i]-'A']);
			else printf("%c",a[i]);
		}
		printf("\n");
	}
}