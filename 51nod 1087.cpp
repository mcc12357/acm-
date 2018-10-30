#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef long long ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll l = 0,r = 100000;
		while(r - l > 1)
		{
			ll mid = (l + r) / 2;
			if((ll)(1+mid)*mid/2+1 < n) l = mid;
			else r = mid;
		}
		if((1+l)*l/2+1==n || (1+r)*r/2+1==n) printf("1\n");
		else printf("0\n");
	}
}