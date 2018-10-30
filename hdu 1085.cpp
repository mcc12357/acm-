#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
/*struct Money
{
	int onenum;
	int twonum;
	int fivenum;
	bool is;
}money[10010];*/
int a,b,c;
int dp[100000];
int main()
{
	while(~scanf("%d %d %d",&a,&b,&c) && (a||b||c))
	{
		int i,j;
		int sum = a + b * 2 + c * 5;
		/*for(i=0;i<=sum;i++) money[i].is = false;
		money[0].is = true;
		money[0].onenum = a;
		money[0].twonum = b;
		money[0].fivenum = c;
		for(i=1;i<=sum;i++)
		{
			if(i>=1 && money[i-1].is && money[i-1].onenum>0)
			{
				money[i] = money[i-1];
				money[i].onenum--;
			}
			if(i>=2 && money[i-2].is && money[i-2].twonum>0)
			{
				money[i] = money[i-2];
				money[]
			}
		}*/
		b = a + b;
		c = b + c;
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(i=0;i<c;i++)
		{
			if(i<a)
			{
				for(j=sum;j>=0;j--)
				{
					if(j>=1 && dp[j-1]) dp[j] = 1;
				}
			}
			else if(i>=a && i<b)
			{
				for(j=sum;j>=0;j--)
				{
					if(j>=2 && dp[j-2]) dp[j] = 1;
				}
			}
			else
			{
				for(j=sum;j>=0;j--)
				{
					if(j>=5 && dp[j-5]) dp[j] = 1;
				}
			}
		}
		for(i=0;i<=sum+1;i++) if(!dp[i]) break;
		printf("%d\n",i);
	}
}