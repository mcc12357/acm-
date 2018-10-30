#include<iostream>
using namespace std;
int main()
{
	int t,m,n,i,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		sum=0;
		for(i=1;i<m;i++)
		{
			if(m%i==0) sum+=i;
		}
		if(sum!=n) printf("NO\n");
		else
		{
			sum=0;
			for(i=1;i<n;i++)
				if(n%i==0) sum+=i;
			if(sum==m) printf("YES\n");
			else printf("NO\n");
		}
	}
}