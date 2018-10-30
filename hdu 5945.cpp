#include <iostream>  
#include <algorithm>  
#include <list>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <queue>  
#include <vector> 
using namespace std;  
typedef _int64 ll;  
const ll mod=1e9+7;  
const int N= 1e6+20;  
int dp[N];//dp[n] n变到1最少步数   
int q[N];//单调队列存下标  
int min(int x,int y)
{
	if(x<y) return x;
	return y;
} 
int main()  
{  
    int cas;  
    cin>>cas;  
    while(cas--)  
    {  
        ll x,k,t;  
        scanf("%I64d %I64d %I64d",&x,&k,&t); 
        if(t==0)//特判:一定有解可以整除   
        {  
            int cnt=0;  
            while(x!=1)  
            {  
                x/=k;  
                cnt++;  
            }  
            cout<<cnt<<endl;  
            continue;  
        }  
        if(k==0)  
        {  
            int cnt;  
            if((x-1)%t==0)  
            cnt=(x-1)/t;  
            else  
            cnt=(x-1)/t+1;  
              
            cout<<cnt<<endl;  
            continue;  
        }  
        int l,r;  
        l=r=1;  
        dp[1]=0;   
        q[1]=1;  
        //dp[i]=min(min(dp[i-t]~dp[i-1])+1,dp[i/k]+1)   
        for(int i=2;i<=x;i++)  
        {  
            while(l<=r&&q[l]<i-t) l++;//过时下标出队  
              
            if(l<=r) dp[i]=dp[q[l]]+1;//op 1   
            if(i%k==0)   
            {  
                dp[i]=min(dp[i],dp[i/k]+1);   
            }  
            while(l<=r&&dp[q[r]]>=dp[i]) r--;//淘汰  
              
            q[++r]=i;   
        }  
        //cout<<endl;   
        cout<<dp[x]<<endl;  
    }  
    return 0;  
}  