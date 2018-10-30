#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int sign[10][100001];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		if(m<0) cout << '-';
		printf("0.");
		int x = 10;
		memset(sign,0,sizeof(sign));
		while(1)
		{
			int a,b;
			a = x / m;
			b = x % m;
			if(sign[a][b]) break;
			printf("%d",a);
			if(b==0) break;
			x = b * 10;
			sign[a][b] = 1;
		}
		printf("\n");
	}
	return 0;
}