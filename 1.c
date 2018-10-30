#include<stdio.h>
int main()
{
	int i,max,j,r;
	char m[1001][15];
	int sum[1001],b[1001],c[1001];
	int t = 1;
	int k,h;
	while(1)
	{		
		scanf("%d",&t);
		if(t==0) break;
		k=0;
		h=0;
		for(i=0;i<1000;i++) {sum[i]=0;b[i]=0;c[1001]=0;}
		for(i=0;i<1001;i++)
			for(j=0;j<15;j++) m[i][j]='0';
		for(i=0;i<t;i++)
		{
			scanf("%s",m[i]);
			
		}
		for(i=0;i<t&&b[i]!=1;i++)
		{
			for(j=i;j<t;j++)
			{
				if(m[j][0]==m[i][0])
				{
					for(r=0;r<15;r++) {if(m[j][r]!=m[i][r]) break;}
					if(r==15)
					{
					sum[k]++;
					b[j]=1;
					}
				}
			}
			for(j=i;j<t;j++)
			{
				if(m[j][0]==m[i][0]) {c[k]=j;break;}
			}
			k++;
			
		}
		i=0;
		max = sum[i];
		while(sum[i])
		{
			if(sum[i]>max) {max=sum[i];h=i;}
			i++;
		}

		printf("%s",m[c[h]]);

		
	}
}