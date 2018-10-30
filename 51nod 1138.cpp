#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef long long ll;
const int len = 100000;
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	bool flag = false;
	for(i=len;i>=2;i--)
	{
		ll l = 1,r = n;
		while(r-l>1)
		{
			ll mid = (l + r) / 2;
			ll x = (2 * mid + i - 1) * i / 2;
			if(x>n) r = mid;
			else l = mid;
		}
		if((2*l+i-1)*i/2==n)
		{
			printf("%lld\n",l);
			flag = true;
		}
		else if((2*r+i-1)*i/2==n)
		{
			printf("%lld\n",r);
			flag = true;
		}
	}
	if(!flag) printf("No Solution\n");
}