#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int a[100005];
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int flag=0;
		int i;
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        sort(a,a+n,cmp);
        int s=0,d=n-1;
        for(i=0;i<n;i++)
        {
            if(a[i]!=a[0])
            {
                flag=1;
                break;
            }
        }
        for(i=n-1;i>0;i--)
        {
            if(a[i]!=a[n-1])
            {
                d=i+1;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(a[i]!=a[0])
            {
                s=i-1;
                break;
            }
        }
        if(flag)
        {
            printf("%d\n",d-s-1);
        }
        else
        {
            printf("0\n");
        }

    }
}