//组合数学p23,例2.3
#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m,k;
		scanf("%d %d",&m,&k);//m个数值,所取值不大于k,m小于100，k小于100
		int a[100],b[100],res[100];//a[i]保存数i价值，b[i]保存数i个数,res[i]表示价值为i时的种类数
		memset(res,0,sizeof(res));
		int i,j,h;
		res[0] = 1;//初始化
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
			if(b[i]==0) continue;
			for(j=k;j>=0;j--)
			{
				for(h=1;h<=b[i] && h*a[i]+j<=k;h++)
				{
					res[j+h*a[i]] += res[j]; 
				}
			}
		}
		int sum = 0;
		for(i=1;i<=k;i++) sum += res[i];
		printf("%d\n",sum);
		//printf("%d %d %d %d\n",res[0],res[1],res[2],res[3]);
	}
	return 0;
}