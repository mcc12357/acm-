#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	char a[15];
	int i,j,m,n,k,r,year,month,day,res;
	while(scanf("%s",a)!=EOF)
	{
		year=0;
		month=0;
		day=0;
		res=0;
		for(i=0;;i++)
		{
			if(a[i]=='/') break;
		}
		m=i;
		for(i=m+1;;i++)
		{
			if(a[i]=='/') break;
		}
		n=i;
		r=strlen(a);
		k=1;
		for(i=m-1;i>=0;i--)
		{
			year+=(a[i]-'0')*k;
			k*=10;
		}
		//printf("%d\n",year);
		k=1;
		for(i=n-1;i>m;i--)
		{
			month+=k*(a[i]-'0');
			k*=10;
		}
		//printf("%d\n",month);
		k=1;
		for(i=r-1;i>n;i--)
		{
			day+=k*(a[i]-'0');
			k*=10;
		}
		//printf("%d\n",day);
		if(month==1) res=day;
		else 
		{
			for(i=1;i<month;i++)
			{
				if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) res+=31;
				if(i==2)
				{
					if(year%4==0&&year%100 || year%400==0) res+=29;
					else res+=28;
				}
				if(i==4 || i==6 || i==9 || i==11) res+=30;
			}
			res+=day;

		}
		printf("%d\n",res);
	}
}