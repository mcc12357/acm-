 
# include<stdio.h>
# include<iostream>
# include<string.h>
using namespace std;
int a[110000][12];
inline int Input()
{
    int res=0,f=1,c;
    while(!isdigit(c = getchar()) && c!='-');
    c=='-' ? f=0 : res=c-'0';
    while(isdigit(c = getchar()))
        res = res*10 + c-'0';
    return f ? res : -res;
}
int max1(int x,int y)
{
	return x>y?x:y;
}
int max(int a,int b,int c)
{
	if(a>b)
		b=a;
	if(c>b)
		b=c;
	return b;
}
int main()
{
	int n,i,j,x,y,m;
	while(scanf("%d",&n)&&n)
	{
		memset(a,0,sizeof(a));
		m=0;
		for(i=0;i<n;i++)
		{
			x=Input();
			y=Input();
			a[y][x]++;
			if(y>m)
				m=y;
		}
		for(i=m;i>0;i--)
		for(j=0;j<11;j++)
		{
			if(j==0)
				a[i-1][j]+=max1(a[i][j],a[i][j+1]);
			else if(j==10)
				a[i-1][j]+=max1(a[i][j],a[i][j-1]); 
			else
				a[i-1][j]+=max(a[i][j-1],a[i][j],a[i][j+1]);
		}
		printf("%d\n",a[0][5]);		
	}
	return 0;
}        