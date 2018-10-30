#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2010;

int n;
__int64 a[N];
__int64 b[N];

bool cmp(__int64 a,__int64 b)
{
return a<b;
}

__int64 dp[N][N];
__int64 min(__int64 x,__int64 y)
{
return x<y?x:y;
}
int main()
{
    //freopen("in.txt","r",stdin);
    __int64 i,j,k,ans;
    cin>>n;
    for(i=1;i<=n;i++)
scanf("%I64d",&a[i]);
    for(i=1;i<=n;i++)
        b[i]=a[i];
sort(b+1,b+1+n,cmp);
    for(j=1;j<=n;j++)
{
        dp[1][j]=a[1]-b[j];
if(dp[1][j]<0)
dp[1][j]=-dp[1][j];
}
__int64 t;
    for(i=2;i<=n;i++)  // 非严格递增
    {
        k=dp[i-1][1];
        for(j=1;j<=n;j++)
        {
            k=min(dp[i-1][j],k);
t=a[i]-b[j];
if(t<0)
t=-t;
            dp[i][j]=k+t;   //dp[i][j] = min{dp[i - 1][0...j] + ?abs(a[i] - b[j])}
        }
    }
ans=dp[n][n];
    for(i=n;i>=1;i--)
        ans=min(ans,dp[n][i]);
    printf("%I64d\n",ans);
    return 0;
}
