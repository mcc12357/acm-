#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
int stick[5000];
int used[5000];
int sum;
int num;
int len;
bool cmp(int x,int y)
{
	return x > y;
}
bool dfs(int curnum,int left,int t)
{
	int i,j;
	if(left==0)
	{
		t -= len;
		if(t==0) return true;
		for(i=0;used[i];i++);
		used[i] = 1;
		if(dfs(i+1,len-stick[i],t)) return true;
		used[i] = 0;
		t += len;
	}
	else
	{
		for(j=curnum;j<num;j++)
		{
			if(j>0 && stick[j]==stick[j-1] && !used[j-1]) continue;
			if(!used[j] && stick[j]<=left)
			{
				left -= stick[j];
				used[j] = 1;
				if(dfs(j,left,t)) return true;
				left += stick[j];
				used[j] = 0;
				if(stick[j]==left) break;
			}
		}
	}
	return false;
}
int main()
{
	while(~scanf("%d",&num) && num)
	{
		int i;
		sum = 0;
		for(i=0;i<num;i++) {scanf("%d",&stick[i]);sum += stick[i];}
		sort(stick,stick+num,cmp);
		bool flag = false;
		for(len=stick[0];len<=sum/2;len++)
		{
			if(sum%len==0)
			{
				memset(used,0,sizeof(used));
				if(dfs(0,len,sum))
				{
					printf("%d\n",len);
					flag = true;
					break;
				}
			}
		}
		if(!flag) printf("%d\n",sum);
	}
}
/*64
40 40 30 35 35 26 15 40 40 40 40 40 40 40 40 40 40 40 40 40 40 
40 40 43 42 42 41 10 4 40 40 40 40 40 40 40 40 40 40 40 40 40 
40 25 39 46 40 10 4 40 40 37 18 17 16 15 40 40 40 40 40 40 40 
40
*/