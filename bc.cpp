#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m,k,i;
		cin >> m >> k;
		if(m<(1+k)*k/2) cout << -1 << endl;
		else
		{
			int av = m / k;
			int n = m - av * k;
			_int64 res = 1;
			int *p1 = new int[5 * 100000000 + 5];
			int *p2 = new int[5 * 100000000 + 5];
			if(n==0 && n%2==0)
			{
				int temp = 1;
				for(i=0;i<k/2;i++)
				{
					p1[i] = av + temp;
					p2[i] = av - temp;
					temp ++;
				}
				for(i=0;i<k/2;i++)
				{
					res *= p1[i];
					res %= (1000000000 +7);
					res *= p2[i];
					res %= (1000000000 +7);
				}
				printf("%I64d\n",res);
			}
			if(n==0 && n%2)
			{
				int temp = 1;
				for(i=0;i<k/2;i++)
				{
					p1[i] = av + temp;
					p2[i] = av - temp;
					temp ++;
				}
				for(i=0;i<k/2;i++)
				{
					res *= p1[i];
					res %= (1000000000 +7);
					res *= p2[i];
					res %= (1000000000 +7);
				}
				res *= av;
				res %= (1000000000 +7);
				printf("%I64d\n",res);
			}
			if(n>0 && n%2==0)
			{
				int temp = 1;
				for(i=0;i<k/2;i++)
				{
					p1[i] = av + temp;
					p2[i] = av - temp;
					temp ++;
				}
				temp = 1;
				int sign = 0;
				while(1)
				{
					for(i=k/2-1;i>=0;i--)
					{
						if(n==0) {sign = 1;break;}
						p1[i] += temp;
						n--;
					}
					for(i=k/2-1;i>=0;i--)
					{
						if(n==0) {sign = 1;break;}
						p2[i] += temp;
						n--;
					}
					if(sign) break;
					temp ++;
				}
				for(i=0;i<k/2;i++)
				{
					res *= p1[i];
					res %= (1000000000 +7);
					res *= p2[i];
					res %= (1000000000 +7);
				}
				printf("%I64d\n",res);
			}
			if(n>0 && n%2)
			{
				int temp = 1;
				for(i=0;i<k/2;i++)
				{
					p1[i] = av + temp;
					p2[i] = av - temp;
					temp ++;
				}
				temp = 1;
				p2[k/2] = av;
				int sign = 0;
				while(1)
				{
					for(i=k/2-1;i>=0;i--)
					{
						if(n==0) {sign = 1;break;}
						p1[i] += temp;
						n--;
					}
					for(i=k/2;i>=0;i--)
					{
						if(n==0) {sign = 1;break;}
						p2[i] += temp;
						n--;
					}
					if(sign) break;
					temp ++;
				}
				for(i=0;i<k/2;i++)
				{
					res *= p1[i];
					res %= (1000000000 +7);
					res *= p2[i];
					res %= (1000000000 +7);
				}
				res *= p2[k/2];
				res %= (1000000000 +7);
				printf("%I64d\n",res);
			}
			delete []p1;
			delete []p2;
		}
	}
}