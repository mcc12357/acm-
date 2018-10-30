#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char a[100],flag[100];
		scanf("%s",a);
		int length;
		length = strlen(a);
		memset(flag,0,sizeof(flag));
		int i;
		for(i=0;i<length - 1;i++)
		{
			if(a[i]=='I' && (a[i+1]=='V'||a[i+1]=='X')) flag[i] = 1;
			if(a[i]=='X' && (a[i+1]=='L'||a[i+1]=='C')) flag[i] = 1;
			if(a[i]=='C' && (a[i+1]=='D'||a[i+1]=='M')) flag[i] = 1;
		}
		int sum = 0;
		for(i=0;i<length;i++)
		{
			if(flag[i]==0)
			{
				if(a[i]=='I') sum += 1;
				if(a[i]=='V') sum += 5;
				if(a[i]=='X') sum += 10;
				if(a[i]=='L') sum += 50;
				if(a[i]=='C') sum += 100;
				if(a[i]=='D') sum += 500;
				if(a[i]=='M') sum += 1000;
			}
			else 
			{
				if(a[i]=='I') sum -= 1;
				if(a[i]=='V') sum -= 5;
				if(a[i]=='X') sum -= 10;
				if(a[i]=='L') sum -= 50;
				if(a[i]=='C') sum -= 100;
				if(a[i]=='D') sum -= 500;
				if(a[i]=='M') sum -= 1000;
			}
		}
		cout << sum << endl;

	}
}