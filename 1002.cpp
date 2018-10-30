#include<iostream>
using namespace std;
int f(int a,int b,int c,int m)
{
	return (a*m*m+b*m+c);
}
int g1(int p1,int p2,int p3,int p4,int p5)
{
	int min=p1;
	if(p2<min) min=p2;
	if(p3<min) min=p3;
	if(p4<min) min=p4;
	if(p5<min) min=p5;
	return min;
}

int g2(int p1,int p2,int p3,int p4,int p5)
{
	int max=p1;
	if(p2>max) max=p2;
	if(p3>max) max=p3;
	if(p4>max) max=p4;
	if(p5>max) max=p5;
	return max;
}
int main()
{
	int t,a,b,c,l,r,max,min,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d %d",&a,&b,&c,&l,&r);
		if(a==0)
		{
			if(f(a,b,c,l)>f(a,b,c,r)) {max=f(a,b,c,l);min=f(a,b,c,r);}
			else {min=f(a,b,c,l);max=f(a,b,c,r);}
		}

		if(a>0)
		{
			if(f(a,b,c,l)>f(a,b,c,r)) {max=f(a,b,c,l);}
			else max=f(a,b,c,r);
			temp = -b/(2*a);
			min=g1(f(a,b,c,l),f(a,b,c,r),f(a,b,c,temp),f(a,b,c,temp+1),f(a,b,c,temp-1));
		}
		if(a<0)
		{
			if(f(a,b,c,l)>f(a,b,c,r)) {min=f(a,b,c,r);}
			else min=f(a,b,c,l);
			temp = -b/(2*a);
			max=g2(f(a,b,c,l),f(a,b,c,r),f(a,b,c,temp),f(a,b,c,temp+1),f(a,b,c,temp-1));
		}
		printf("%d %d\n",max,min);
	}
}