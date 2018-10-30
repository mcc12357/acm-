#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
int dp[2010][2010];
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int main() {
    int m,len,i,j,a,b,temp,temp2;
    char s[2010],t[5];
    int cost[30];
    while(~scanf("%d %d",&m,&len)) {
        scanf("%s",s);
        for(i = 0; i < m; i++) {
            scanf("%s %d %d",t,&a,&b);
            cost[t[0]-'a'] = min(a,b);
        }
        for(i = len-2; i >= 0; i--){
            for(j = i+1; j < len; j++){
                dp[i][j] = min(dp[i+1][j]+cost[s[i]-'a'],dp[i][j-1]+cost[s[j]-'a']);
                if(s[i] == s[j]) dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}