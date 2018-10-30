#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
bool is[150][15];
int dp[110][1<<11][1<<11];
int n,m,t=0;
int can[150];
void Init()
{
    for(int i=0;i<(1<<10);i++) 
    {
        if((i&(i<<1)) || (i&(i<<2))) continue;
        can[++t] = i; 
    }
    return;
}
int check(int x,int state)
{
    int cnt = 0;
    if( state >= pow((int)2,m) ) return -1;
    for(int i=1;i<=m;i++)
    {
        if( ((1<<(i-1)) & state )) cnt++;
        if(!is[x][i])
        {
            if( ((1<<(m-i)) & state)) return -1;
        }
    }
    return cnt;
}
int main()
{
    //freopen("duipai.out","r",stdin);
	int i,j,k,q;
    Init();  scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
          {
              char op;  scanf(" %c",&op);
              if( op =='P') is[i][j] = true;
              else is[i][j] = false;
          }

        int ans = 0,now;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=t;j++)
            {
                int cnt = check(i,can[j]);
                if( cnt!=-1 ){
                    //cout<<i<<"  "<<can[j]<<"  "<<cnt<<endl;
                    for(int k = 1; k<=t;k++)
                    {
                        if( !(can[k]&can[j]) ){
                          dp[i][can[j]][can[k]] = cnt;
                          now = 0;
                            for(q = 1;q<=t;q++)
                            {
                                if(i==1) ;
                                else {
                                   if(!(can[q]&can[j])) now = max(now,dp[i-1][can[k]][can[q]]);
                                  }
                             }
                        }
                        dp[i][can[j]][can[k]] += now;
                    if(i==n) ans = max(ans,dp[i][can[j]][can[k]]);
                    }
                }
            }
        }
        printf("%d\n",ans);
    return 0;
}