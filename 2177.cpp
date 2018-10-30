#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,i,m;
	double k;
	while(scanf("%d %d",&a,&b)!=EOF && a && b)
	{
		if(a>b) swap(a,b);
		k=(sqrt(5.0)+1)/2;
		if(a == (int)((b-a)*k)) printf("0\n");
		else 
		{
			printf("1\n");
			//先输出取走相同数量石子剩余石子
			m=b-a;
			for(i=1;i<a;i++)//i表示a堆剩余石子
			{
				if(i == (int)((b-a)*k)) printf("%d %d\n",i,i+m);
			}
			//再输出在一堆中取任意多石子的情况。只可能在多的b堆中取，若在a堆中取，则b-a变大，不可能变为奇异局势
			for(i=0;i<b;i++)//i表示b取完后剩下的石子
			{
				if(a>i)//注意可能b拿完后剩下的小于a，故需要讨论
				{	
					if(i == (int)((a-i)*k)) printf("%d %d\n",i,a);
				}
				else if(a == (int)(i-a)*k) printf("%d %d\n",a,i);
			}
		}
	}
}