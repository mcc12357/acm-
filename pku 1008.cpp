#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
//不能写成string a,b,否则无法访问
char a[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char b[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	printf("%d\n",t);
	for(i=1;i<=t;i++)
	{
		int day,year;
		string month;
		int mon;
		scanf("%d",&day);
		getchar();
		//scanf(" %s",&month);不能这样写
		cin >> month;
		scanf("%d",&year);
		int j;
		for(j=0;j<19;j++) if(month.compare(a[j])==0) mon = j;
		int sumday = year * 365 + mon * 20 + day;
		int nyear = sumday / 260;
		int daynum = sumday % 13 + 1;
		int dayname = sumday % 20;
		printf("%d %s %d\n",daynum,b[dayname],nyear);
	}
}