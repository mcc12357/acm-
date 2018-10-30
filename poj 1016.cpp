#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
char dit[85];
char ori[85];
int len;
int num[15];
map<int,const char*> m;
map<int,const char*>::iterator ite;
bool selfjudge(char a[])
{
	int i;
	memset(num,0,sizeof(num));
	for(i=0;i<len;i++)
	{
		num[a[i]-'0']++;
	}
	int t1,t2;
	for(i=0;i<len;i++)
	{
		if(i%2==0)
		{
			t1 = a[i] - '0';
		}
		else
		{
			t2 = a[i] - '0';
			if(num[t2]!=t1) return false;
		}
	}
	return true;
}
void change(char a[])
{
	int i;
	memset(num,0,sizeof(num));
	for(i=0;i<len;i++)
	{
		num[a[i]-'0']++;
	}
	int k = 0;
	for(i=0;i<=9;i++)
	{
		if(num[i])
		{
			a[k++] = num[i] + '0';
			a[k++] = i + '0';
		}
	}
}
int main()
{
	while(~scanf("%s",ori) && ori[0]!='-')
	{
		len = strlen(ori);
		char tmp[80];
		m.clear();
		strcpy(dit,ori);
		if(selfjudge(ori)) printf("%s is self-inventorying\n",ori);
		else
		{
			int i,j;
			m.insert(pair<int,const char*>(0,ori));
			int flag = 0;
			for(i=1;i<=15;i++)
			{
				change(dit);
				if(selfjudge(dit))
				{
					printf("%s is self-inventorying after %d steps\n",ori,i);
					flag = 1;
					break;
				}
				m.insert(pair<int,const char*>(i,dit));
				//ite = m.find(i);
				//if(i>=2) ite1 = m.find(2);
				//printf("%d %s\n",i,ite->second);
				//ite = m.find(1);
				//if(i>=2)strcpy(tmp,ite1->second);
				for(j=0;j<i;j++)
				{
					ite = m.find(j);
					//if(i>=2) strcpy(tmp,ite1->second);
					//strcpy(tmp,ite->second);
					if(strncmp(dit,ite->second,len)==0)
					{
						//if(i>=2) strcpy(tmp,ite1->second);
						printf("%s enters an inventory loop of length %d\n",ori,i-j);
						flag = 1;
						break;
					}
				}
				if(flag) break;
				//printf("%s\n",dit);
			}
			if(!flag) printf("%s can not be classified after 15 iterations\n",ori);
		}
	}
}