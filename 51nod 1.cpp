#include <iostream>  
#include<stdio.h>
using namespace std;  
#define N 400  
int a[N],b[N],c[2*N];  
char ch1[N];
int cal()
{
	int i = 0 , j =0;
	for(i = 0 ; i < 2*N ; ++i){  
        c[i] = 0;  
    }  
    for(i = 0 ; i < N ; ++i){  
        for(j = 0 ; j < N ; ++j){  
            c[i+j] += a[i] * b[j];  
        }  
    }  
    for(i = 0 ; i < 2*N -1 ; ++i){  
        c[i+1] += c[i] /10;  
        c[i] = c[i] % 10;  
    }  
    j = 2*N -1;  
  
    while(c[j] == 0)    
               j--;    
	for(i = j;i >= 0; --i) a[i] = c[i];
	//printf("j=%d\n",j);
	return j;

}
int main()  
{   
	int n,i,j;
    scanf("%s %d",ch1,&n);  
    int pos = -1;
	for(i=0;i<6;i++) if(ch1[i]=='.') pos = i;
	int k = 0;
	for(i=0;i<6;i++)
	{
		if(i==0 && ch1[i]=='0') continue;
		if(ch1[i]=='.') continue;
		a[k] = ch1[i] - '0';
		//b[k] = a[k];
		k++;
	}
	k--;
	int num = 0;
	for(i=5;i>=0;i--) 
	{
		if(ch1[i]!='0') break;
		k--;
		num++;
	}
	int total = (5 - pos - num) * n;;
	//printf("%d",a[k]);
	//printf("\n");
	for(i=0;i<=k;i++) b[i] = a[k-i];
	for(i=0;i<=k;i++) {a[i] = b[i];}
    //char_to_int(a , ch1);  
    for(i = 0 ; i < 2*N ; ++i){  
        c[i] = 0;  
    }  
    for(i=1;i<n;i++)
	{
		k = cal();
	}
	for(i=0;i<=k;i++) b[i] = a[k-i];
	if(pos==-1)
	{
		bool flag = false;
		//int num = 0;
		for(i=0;i<=k;i++)
		{
			if(a[i]!=0) flag = true;
			if(flag) printf("%d",b[i]);
		}
		printf("\n");
	}
	else
	{
		bool flag = false;
		
		if(total>=k+1) flag = true;
		//printf("k = %d total = %d\n",k,total);
		if(flag) printf(".");
		for(i=1;i<=total-k-1;i++) 
		{
			printf("0");
		}
		for(i=0;i<=k-total;i++) 
		{
			if(i==0 && a[i]=='0') continue;
			printf("%d",b[i]);
		}
		if(!flag && total) printf(".");
		for(;i<=k;i++) printf("%d",b[i]);
		printf("\n");
	}
    return 0;    
}  