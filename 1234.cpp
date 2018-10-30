#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[100005];
int main()
{
    long long m,n;
    while(~scanf("%lld %lld",&n,&m))
    {
        long long ans=10000001;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        if(m==1)
        {
            printf("0\n");
            continue;
        }
        for(int h=0;h<n-m;h++)
        {
            long long res = 0;
            if(m%2==0)
            {

                for(int i=h+(m/2)-1, j=i+1;i>=h;i--,j++)
                {
                    res+=(a[j]-a[i])*(j-i);
                }
                if(res<ans)
                {
                    ans=res;
                }

            }
            else
            {
                int i=h+(m/2)-1;
                res=(a[i+2]-a[i])*2;
                if(m==3)
                    {
                        if(res<ans)
                        {
                            ans=res;
                        }
                    }
                else{
                    for(int i=h+(m/2)-2, j=i+4;i>=h;i--,j++)
                    {
                        res+=(a[j]-a[i])*(j-i);
                    }
                    if(res<ans)
                    {
                        ans=res;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
