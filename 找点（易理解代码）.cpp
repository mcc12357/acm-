/*先按右端点从小到大排，如果右端点一样，在按左端点从大到小排。取点时每次取第一个区间的右端点，
然后看后一个区间的左端点，如果后一个区间右端点大于第一个区间左端点，则需要再找一个点，此时取
第二个区间的右端点继续循环。*/
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