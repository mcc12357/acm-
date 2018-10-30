#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<map>
#define maxn 10000010
map<int,int> m;
int a[maxn];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i;
		m.clear();
		int ans = 0;
		int res = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			m[a[i]]++;
			if(ans<m[a[i]])
			{
				ans = m[a[i]];
				res = a[i];
			}
		}
		printf("%d\n",res);
	}
}