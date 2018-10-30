#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<set>
#include<vector>
typedef _int64 ll;
const int mod = 1e9 + 7;
set<int> s;
set<int> ::iterator ite;
vector<int> g;
int main()
{
	int i,j;
	ll m = 2;
	double tm;
	//printf("2\n");
	//s.insert(2);
	//g.push_back(2);
	int flag = 0;
	for(i=1;i<=100000;i++)
	{
		tm = 2 * m * (m-1);
		tm = sqrt(tm*1.0);
		//printf("%d %lf\n",i,m);
		ll tt = (ll)tm;
		m = (3 * m - 1 + 2 * tt) % mod;
		for(j=0;j<g.size();j++) 
		{
			if(m==g[j]) {flag = 1;break;}
		}
		g.push_back(m);
		if(flag) break;
		//ite = s.find((int)m);
		//if(ite==s.end()) s.insert(m);
		//else break;
		//printf("%I64d\n",m);
		
	}
	printf("i = %d\n j = %d %d %d",i,j,g[j],m);

}