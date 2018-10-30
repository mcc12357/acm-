#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<cmath>
int point[12];
int real[12];
int main()
{
	char left[3][6],right[3][6],result[3][5];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		memset(point,0,sizeof(point));
		memset(real,0,sizeof(real));
		for(i=0;i<3;i++)
		{
			cin>>left[i];
			cin>>right[i];
			cin>>result[i];
		}
		for(i=0;i<3;i++)
		{
			int len = strlen(left[i]);
			switch(result[i][0])
			{	
				case 'e':
				{
					for(j=0;j<len;j++)
					{
						real[left[i][j]-'A'] = 1;
						real[right[i][j]-'A'] = 1;
					}
					break;
				}
				case 'u':
				{
					for(j=0;j<len;j++)
					{
						point[left[i][j]-'A']++;
						point[right[i][j]-'A']--;
					}
					break;
				}
				case 'd':
				{
					for(j=0;j<len;j++)
					{
						point[left[i][j]-'A']--;
						point[right[i][j]-'A']++;
					}
					break;
				}
			}
		}
		/*int tmax = 0;
		for(i=0;i<12;i++)
		{
			if(fabs(point[tmax])<=fabs(point[i]) && !real[i]) tmax = i;
		}
		if(point[tmax]>0)
		{
			printf("%c is the counterfeit coin and it is heavy.\n",tmax+'A');
		}
		else
		{
			printf("%c is the counterfeit coin and it is light.\n",tmax+'A');
		}*/
		int max=-1;  //查找被怀疑程度最高的硬币（假币）
		char alpha;
		char tm;
		for(tm='A';tm<='L';tm++)
		{
			if(real[tm-'A'])  //绝对真币
				continue;

			if(max<=fabs(point[tm-'A']))
			{
				max=fabs(point[tm-'A']);
				alpha=tm;
			}
		}

		cout<<alpha<<" is the counterfeit coin and it is ";
		if(point[alpha-'A']>0)
			cout<<"heavy."<<endl;
		else
			cout<<"light."<<endl;
	}
}