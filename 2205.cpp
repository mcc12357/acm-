#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	char str[105],str2[52];
	int tag[105];
	while(gets(str)&&gets(str2))
	{
		int m,i,j,t=1;
		strcat(str,str2);
		m=strlen(str);
		//printf("%d",m);
		//for(i=0;i<m;i++) printf("%c",str[i]);
		memset(tag,0,sizeof(tag));
		for(i=0;i<m;i++)
		{
			if(tag[i]) continue;
			tag[i]=t;
			for(j=i+1;j<m;j++)
			{
				if(str[j]==str[i])
				{
					tag[j]=t;
				}

			}
			t++;
		}
		t--;
		int sum=0,k,r=0;
		for(i=1;i<=t;i++)
		{
			k=0;
			for(j=0;j<m;j++)
			{
				if(tag[j]==i) 
				{
					k++;
				}
			}
			if(k%2) 
			{
				r=1;
				sum+=k;
				sum--;
			}
			if(k%2==0)
			{
				sum+=k;
			}
		}
		if(r) sum++;
		//for(i=0;i<m;i++) printf("%c",str[i]);
		printf("%d\n",sum);
	}
}

