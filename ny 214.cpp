//时间复杂度为n平方，超时
#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[100000+1],res[100000+1];
		int i,j;
		for(i=0;i<n;i++) {scanf("%d",&a[i]);res[i] = 1;}
		for(i=0;i<n;i++)
			for(j=0;j<i;j++) if(a[i]>a[j]) res[i] = max(res[i],res[j] + 1);
		int pp = res[0]; 
		for(i=0;i<n;i++) if(pp<res[i]) pp = res[i];
		cout << pp << endl;
	}

}