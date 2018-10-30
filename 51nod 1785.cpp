#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#define maxn 1000010
int a[110];
int v[maxn];
int main()
{
	int n,k,s;
	scanf("%d %d",&n,&k);
	int i,j;
	int t = 0;
	double sum = 0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s);
		if(s==1)
		{	
			scanf("%d",&v[t]);
			sum += v[t];
			a[v[t]]++;
			if(t>=k)
			{
				a[v[t-k]]--;
				sum -= v[t-k];
			}
			t++;
		}
		else if(s==2)
		{
			if(t>=k) printf("%.2f\n",(sum / k)-((sum / k)-(int)(sum / k)));
			else printf("%.2f\n",(sum / t)-((sum / t)-(int)(sum / t)));
		}
		else if(s==3)
		{
			int av = sum / k;
			double res = 0;
			for(j=0;j<=100;j++)
			{
				res += a[j] * (j - av) * (j - av);
			}
			if(t>=k) printf("%.2f\n",res/k);
			else printf("%.2f\n",res/t);
		}
		else
		{
			int r = 0;
			if(t>=k)
			{
				r += a[j];
				for(j=0;j<=100;j++)
				{
					if(r>=k/2+1)
					{
						break;
					}
				}
				if(a[j]>1) printf(".2f\n",(double)j);
				else
				{
					int m;
					for(m=j-1;m>=0;m--) if(a[m]) break;
					printf("%.2f\n",(m+j)/2.0);
				}
			}
			else 
			{
				r += a[j];
				for(j=0;j<=100;j++)
				{
					if(r>=t/2+1)
					{
						break;
					}
				}
				if(a[j]>1) printf(".2f\n",(double)j);
				else
				{
					int m;
					for(m=j-1;m>=0;m--) if(a[m]) break;
					printf("%.2f\n",(m+j)/2.0);
				}
			}
		}
	}
}