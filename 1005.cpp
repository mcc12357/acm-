#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int a,b,n,res[8][8],m[50];
	while(1)
	{
		scanf("%d %d %d",&a,&b,&n);
		if(a==0 && b==0 &&n==0) break;
		if(n==1 || n==2) printf("1\n");
		if(n>=3)
		{				
			int r = 0;
			for(int i=1;i<=7;i++)
				for(int j=1;j<=7;j++) res[i][j] = 7;

			int f1=1,f2=1,f3,t=3,q=3;
			m[1] = 1;
			m[2] = 1;
			for(int k=3;k<=n;k++)
			{

				if(res[f1][f2]==7) 
				{
					f3 = (a * f2+ b * f1) % 7;
					res[f1][f2] = f3;
					m[t++] = f3; 
				}

				else
				{
					t--;
					for(int q=2;q<=n;q++)
						if(m[q] == f2 && m[q-1]==f1) break;
					r = 1;
				}
				f1 = f2;
				f2 = f3;
				if(r) break;
			}
			//for(int u=1;u<=t;u++) printf("%d",m[u]);
			if(r==1) printf("%d\n",m[q-2+(n-q+2)%(t-q)]);
			else printf("%d\n",f3);

		}

	}
}