#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int mapn[10][10];
int sum[10][10];///由（1,1）跟（i，j）确定的矩形的所有元素和
int w[10];///预处理时用
int dp[16][10][10][10][10];
int n;

void DP()
{
    for(int k=1;k<=n;k++)
        for(int x1=1;x1<=8;x1++)
        for(int x2=1;x2<=8;x2++)
        for(int y1=1;y1<=8;y1++)
        for(int y2=1;y2<=8;y2++)
    {
        int r1,r2;
        for(int a=x1;a<x2;a++)
        {
            int loc_s1,loc_s2;
            loc_s1=sum[x2][y2]+sum[a+1][y1]-sum[a+1][y2]-sum[x2][y1];
            loc_s2=sum[a][y2]+sum[x1][y1]-sum[x1][y2]-sum[a][y1];
            r1=min(dp[k-1][x1][y1][a][y2]+loc_s1,dp[k-1][a+1][y1][x2][y2]+loc_s2);
        }
        for(int b=y1;b<y2;b++)
        {
            int loc_s3,loc_s4;
            loc_s3=sum[x2][y2]+sum[x1][b+1]-sum[x1][y2]-sum[x2][b+1];
            loc_s4=sum[x2][b]+sum[x1][y1]-sum[x1][b]-sum[x2][y1];
            r2=min(dp[k-1][x1][y1][x2][b]+loc_s3,dp[k-1][x1][b+1][x2][y2]+loc_s4);
        }
        dp[k][x1][y1][x2][y2]=min(r1,r2);
    }
}

int main()
{
    long double ans;
    while(~scanf("%d",&n))
    {
        memset(mapn,0,sizeof(mapn));
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
        {
            int sd;
            scanf("%d",&sd);
            mapn[i][j]=sd;
            if(i==1)
            {
                w[j]=sd;
            }
        }
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
        {
            w[j]=w[j]+mapn[i][j];
            sum[i][j]=sum[i][j-1]+w[j];
        }
        DP();
        ans=dp[n][8][8][8][8]/(n*1.0)-(sum[8][8]/n)*(sum[8][8]/n);
        cout<<dp[n][8][8][8][8]<<endl;
        cout<<ans<<endl;
    }
}
