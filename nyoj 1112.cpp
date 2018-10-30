#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<set>
struct ss
{
	bool operator () (const char *s1,const char* s2)
	{
		return strcmp(s1,s2) < 0;
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		char a[100005];
		scanf("%d %s",&n,a);
		set<const char*,ss> s;
		set<const char*,ss>::iterator ite;
		int ans = 0;
		int i,j;
		int m = strlen(a);
		char b[12];
		for(i=0;i+n-1<m;i++)
		{
			for(j=0;j<=n-1;j++) b[j] = a[j+i]; 
			ite = s.find(b);
			if(ite==s.end()) s.insert(b);
			else ans++;
		}
		printf("%d\n",ans);

	}
	return 0;
}