#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<string>
int stamp[100];
int num;
int goal;
int result[4];
int resnum;
int reskind;
int maxpoint;
int kind[4];
bool tie;
void dfs(int index,int totalnum,int cur,int kindnum)
{
	if(totalnum>4 || cur>goal || (totalnum==4&&cur!=goal)) return ;
	//totalnum++;
	if(cur == goal)
	{
		int totalpoint;
		int i;
		//int tkind = 1;
		//for(i=1;i<4;i++) if(kind[i-1]!=kind[i]) tkind++;
		totalpoint = kindnum * 100 + (4-totalnum) * 10 + stamp[index];
		if(totalpoint>maxpoint)
		{
			maxpoint = totalpoint;
			resnum = totalnum;
			reskind = kindnum;
			tie = false;
			for(i=0;i<totalnum;i++) result[i] = kind[i];
		}
		else if(totalpoint==maxpoint) tie = true;
		return ;
	}
	if(cur+stamp[index]>goal) return;
	int i;
	kind[totalnum] = stamp[index];
	dfs(index,totalnum+1,cur+stamp[index],kindnum);
	for(i=index+1;i<num;i++)
	{
		if(cur+stamp[i]>goal) break;
		kind[totalnum] = stamp[i];
		dfs(i,totalnum+1,cur+stamp[i],kindnum+1);
	}
}
int main()
{
	while(1)
	{
		num = 0;
		while(~scanf("%d",&stamp[num]) && stamp[num]) num++;
		sort(stamp,stamp+num);
		while(~scanf("%d",&goal) && goal)
		{
			//memset(kind,0,sizeof(0));
			//memset(result,0,sizeof(result));
			resnum = -1;
			maxpoint = -1;
			reskind = -1;
			tie = false;
			int i;
			for(i=0;i<num;i++) 
			{
				if(stamp[i]>goal) break;
				kind[0] = stamp[i];
				dfs(i,1,stamp[i],1);
			}
			if(resnum==-1 && maxpoint==-1 && reskind==-1) printf("%d ---- none\n",goal);
			else
			{
				if(tie)
				{
					printf("%d (%d): tie\n",goal,reskind);
				}
				else
				{
					printf("%d (%d): ",goal,reskind);
					for(i=0;i<resnum-1;i++) printf("%d ",result[i]);
					printf("%d\n",result[resnum-1]);
				}
			}

		}
	}
}
