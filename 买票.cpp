#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
const int MAXN=500;
int f[MAXN],a[MAXN];
int main()
{
    int i,j,t,k,n,m;
    int x;
    int c,s;
    int sign;
    k=0;
    while(cin>>m>>n&&!(m==0&&n==0))
    {
        printf("Test #%d:\n",++k);
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        f[0]=1;
        for(i=2; i<=m+n; i++)
        {
            c=0;
            for(j=0; j<MAXN; j++)
            {
                s=f[j]*i+c;
                f[j]=s%10;
                c=s/10;
            }
        }
        c=0;
        if(m>=n)
        {
            x=m-n+1;
            for(i=0; i<MAXN; i++)
            {
                s=f[i]*x+c;
                f[i]=s%10;
                c=s/10;
            }
            t=0;
            for(j=MAXN-1; j>=0; j--) if(f[j]) break;
            for(i=j; i>=0; i--) a[t++]=f[i];
            x=m+1;
            c=0;
            sign=0;
            for(i=0; i<t; i++)
            {
                s=((c*10)+a[i])/x;
                if(s!=0) sign=1;
                if(sign!=0) cout<<s;
                c=(c*10+a[i])%x;
            }
        }
        else cout<<"0";
        cout<<endl;
    }
    return 0;
}