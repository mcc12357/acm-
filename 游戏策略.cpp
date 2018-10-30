#include<iostream>
#include<stdio.h>
using namespace std;
int min(int a ,int b)
{
	if(a<b) return a;
	else return b;
}

int f(int m)
{
	int t=0;
	while(1)
	{
		if(m%2==0) t++;
		else break;
		m/=2;
	}
	return t;
}
int f1(int r)
{
	int t=1;
	int i;
	for(i=1;i<=r;i++) t*=2;
	return t;
}
int main()
{
	int t,n,a,b,r,t1,t2,p,q=1,w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&a,&b);
		t1=f(a);
		t2=f(b);
		r=min(t1,t2);
		//printf("%d\n",r);
		p=f1(r);
		//printf("%d\n",p);
		w=n/p-2;
		if(w%2==0) printf("Case #%d: Iaka\n",q);
		if(w%2) printf("Case #%d: Yuwgna\n",q);
		q++;
	}
}