/*�Ȱ��Ҷ˵��С�����ţ�����Ҷ˵�һ�����ڰ���˵�Ӵ�С�š�ȡ��ʱÿ��ȡ��һ��������Ҷ˵㣬
Ȼ�󿴺�һ���������˵㣬�����һ�������Ҷ˵���ڵ�һ��������˵㣬����Ҫ����һ���㣬��ʱȡ
�ڶ���������Ҷ˵����ѭ����*/
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node
{
	int beg;
	int end;
}a[100];

bool cmp(node a,node b)
{
	if(a.end != b.end)
	{
		return a.end<b.end;
	}
	else
	{
		return a.beg>b.beg;
	}
}
int main()  
{  
    int i,j,n,m1,m2,sum,x;  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(i=0;i<n;i++)  
        scanf("%d %d",&a[i].beg,&a[i].end);  
        sort(a,a+n,cmp);  
		m2=a[0].end;
		sum=1;
		x=0;  
        for(i=1;i<n;i++)  
        {
            if(a[i].beg>m2)  
            {  
                sum++;   
                m2=a[i].end;  
            }  
        }  
          
        printf("%d\n",sum);  
    }  
    return 0;  
}          