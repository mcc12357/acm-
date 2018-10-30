#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char s[100005];
int a[100005];
int main()
{
    int L,N;
    int ans;
    int x;
    char c;
    while(~scanf("%d%d",&L,&N))
    {
        ans=0;
        cin>>s;
        memset(a,0,sizeof(a));
        for(int i=0;i<L;i++)
        {
            if(s[i]=='.')
            {
                a[i+1]=1;
            }
            else
            {
                a[i+1]=0;
            }
        }
        for(int i=2;i<=L;i++)
        {
            if(a[i-1]==1&&a[i]==1)
            {
                ans++;
            }
        }
        for(int i=1;i<=N;i++)
        {
            scanf("%d %c",&x,&c);
            if((s[x-1]=='.'&&c=='.')||(s[x-1]!='.'&&c!='.')){printf("%d\n",ans); continue;}
            if(c!='.')
            {
                if(a[x-1]==1&&a[x+1]==1)
                {
                    ans=ans-2;
                }
                else if(a[x-1]==0&&a[x+1]==0){printf("%d\n",ans); s[x-1]=c; a[x]=0; continue;}
            }
            else
            {
                if(a[x-1]+a[x+1]==2)
                {
                    ans=ans+2;
                }
                else if(a[x-1]==0&&a[x+1]==0){printf("%d\n",ans);s[x-1]=c; a[x]=1; continue;}
                else if(a[x-1]+a[x+1]==1){ans++;}
            }
            if(c=='.')
            {
                s[x-1]=c;
                a[x]=1;
            }
            else{s[x-1]=c; a[x]=0;}
            printf("%d\n",ans);
        }

    }
}


