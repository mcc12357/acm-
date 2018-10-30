#include<iostream>
using namespace std;
int main()
{
	char m;
	int n,i,j,t,temp=0;
	while(1)
	{
		scanf("%c",&m);
		if(m=='@') break;
		scanf("%d",&n);
		getchar();
		if(temp) putchar(10);
		temp=1;
		t=n-1;
		while(t--) printf(" ");
		printf("%c\n",m);
		for(i=2;i<n;i++)
		{
			t=n-i;
			while(t--) printf(" ");
			printf("%c",m);
			j=2*(i-1)-1;
			while(j--) printf(" ");
			printf("%c\n",m);
		}

		if(n>1) {t=2*n-1; while(t--) printf("%c",m);printf("\n");}
		//printf("\n");

	}
}