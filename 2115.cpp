#include<iostream>
using namespace std;
#include<string.h>
struct stu
{
	char name[20];
	char time[8];
	int min;
	int sec;
	int rank;
};
void trans(stu &a,stu &b)
{
	stu temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int t,casenum = 1;
	while(scanf("%d",&t)!=EOF && t)
	{
		int i,j;
		stu player[10];
		for(i=0;i<t;i++)
		{
			scanf("%s",player[i].name);
			scanf("%s",player[i].time);
		}
		for(i=0;i<t;i++)
		{
			player[i].min = player[i].time[1] - '0' + (player[i].time[0] - '0') * 10;
			player[i].sec = player[i].time[4] - '0' + (player[i].time[3] - '0') * 10;
		}
		for(i=0;i<t;i++)
		{
			for(j=0;j<t-i-1;j++)
			{
				if(player[j].min>player[j+1].min) trans(player[j],player[j+1]);
				else
				{
					if(player[j].min==player[j+1].min && player[j].sec>player[j+1].sec)
					{
						trans(player[j],player[j+1]);
					}
					else 
					{
						if(player[j].min==player[j+1].min && player[j].sec==player[j+1].sec)
						{
							if(!strcmp(player[j].name,player[j+1].name)) trans(player[j],player[j+1]);
						}
					}
				}
			}
		}
		int k = 1;
		int sign[10];
		memset(sign,0,sizeof(sign));
		for(i=0;i<t;i++)
		{
			player[i].rank = k;
			if(sign[i]) k++;
			if(i<t && player[i].min==player[i+1].min && player[i].sec==player[i+1].sec)
			{
				k--;
				sign[i+1] = 1;
			}
			k++;
		}
	if(casenum==1) printf("Case #%d\n",casenum);
	else {printf("\nCase #%d\n",casenum);}
	casenum++;
	for(i=0;i<t;i++)
	{
		printf("%s %d\n",player[i].name,player[i].rank);
	}
	}
}