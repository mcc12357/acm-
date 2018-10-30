/*
dp[i+1][j][0]:放到第i位并且余数为j不含13
dp[i+1][j][1]:放到第i位并且余数为j不含13并且最高位为3
dp[i+1][j][2]:放到第i位并且余数为j含13
*/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=12;
int md[N],dp[N][13][3];

void Init(){
    md[0]=1;
    for(int i=1;i<N;i++)
        md[i]=md[i-1]*10%13;
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<N-1;i++)
        for(int j=0;j<13;j++){
            for(int k=0;k<10;k++)
                dp[i+1][(j+md[i]*k)%13][0]+=dp[i][j][0];
            dp[i+1][(j+md[i])%13][0]-=dp[i][j][1];
            dp[i+1][(j+md[i]*3)%13][1]+=dp[i][j][0];
            dp[i+1][(j+md[i])%13][2]+=dp[i][j][1];
            for(int k=0;k<10;k++)
                dp[i+1][(j+md[i]*k)%13][2]+=dp[i][j][2];
        }
}

int Solve(int x){
    int digit[15],len=0;
    while(x){
        digit[len++]=x%10;
        x/=10;
    }
    digit[len]=0;
    int flag=0,ans=0,mod=0;
    for(int i=len-1;i>=0;mod=(mod+digit[i]*md[i])%13,i--){
        for(int j=0;j<digit[i];j++)
            ans+=dp[i][(13-(mod+j*md[i])%13)%13][2];
        if(flag){
            for(int j=0;j<digit[i];j++)
                ans+=dp[i][(13-(mod+j*md[i])%13)%13][0];
        }else{
            if(digit[i+1]==1 && digit[i]>3)
                ans+=dp[i+1][(13-mod)%13][1];
            if(digit[i]>1)
                ans+=dp[i][(13-(mod+md[i])%13)%13][1];
        }
        if(digit[i+1]==1 && digit[i]==3)
            flag=1;
    }
    return ans;
}

int main(){

    //freopen("input.txt","r",stdin);

    Init();
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",Solve(n+1));
    }
    return 0;
}