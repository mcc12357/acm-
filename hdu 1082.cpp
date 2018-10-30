#include<iostream>
using namespace std;
#include<stdio.h>
#include<stack>
#define maxn 100010
typedef _int64 ll;
int n;
int a[maxn],b[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		char c;
		int h,l;
		cin>>c>>h>>l;
		a[c-'A'] = h;
		b[c-'A'] = l;
	}
	char s[maxn];
	while(~scanf("%s",s))
	{
		stack<int> st;
		while(!st.empty()) st.pop();
		int m = strlen(s);
		if(m==1) printf("0\n");
		else
		{
			int k = 26;
			bool flag = true;
			ll ans = 0;
			for(i=0;i<m;i++)
			{
				if(s[i]==')')
				{
					if(!st.empty())
					{
						int tm2 = st.top();
						st.pop();
						int tm1 = st.top();
						st.pop();
						if(b[tm1]!=a[tm2])
						{
							flag = false;
							break;
						}
						else
						{
							ans += a[tm1] * b[tm1] * b[tm2];
							a[k] = a[tm1];
							b[k] = b[tm2];
							st.push(k);
							k++;
						}
					}
				}
				else if(s[i]>='A' && s[i]<='Z')
				{
					st.push(s[i]-'A');
				}
			}
			if(flag) printf("%I64d\n",ans);
			else printf("error\n");
		}
	}
}