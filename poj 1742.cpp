#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 100100
#define MAX_C 1010

int n,m;
int a[MAX_N],c[MAX_C];
int dp[MAX_N];  //前i种加和成j，i的剩余

void solve(){
        memset(dp, -1, sizeof(dp));

        dp[0] = c[0];
        for(int i = 0;i < n; i++){
                for(int j = 0;j <= m; j++){
                        if(dp[j] != -1) dp[j] = c[i];

                        if(dp[j] == -1){
                                if(j >= a[i] && dp[j-a[i]] != -1){
                                        dp[j] = dp[j - a[i]] - 1;
                                }
                        }
                }
        }
        int sum = 0;
        for(int j  = 1;j <= m; j++){
                if(dp[j] != -1) sum++;
        }
        printf("%d\n", sum);

}
int main(){
        while(scanf("%d%d", &n, &m) && n && m)  {
              for(int i = 0;i < n; i++)
                      scanf("%d", &a[i]);
              for(int i = 0;i < n; i++)
                      scanf("%d", &c[i]);
              
                solve();


        }
        return 0;       
}
