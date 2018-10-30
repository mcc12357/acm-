//_int64范围内任何一个数的质因子个数不会超过100
#include<iostream>
#include<ctime>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#define bint long long
const int TIME = 8;
using namespace std; 
bint factor[1000],aa[1000];
int fac_top=-1;
bint abs(bint a){
 return a>0?a:-a;
}
bint gcd(bint small,bint big){
    while(small){
          swap(small,big);
          small%=big;
    }
    return abs(big);
}

//ret = (a*b)%n (n<2^62)
bint muti_mod(bint a,bint b,bint n){
    bint exp = a%n, res = 0;
    while(b){
        if(b&1){
            res += exp;
            if(res>n) res -= n;
        }
        exp <<= 1;
        if(exp>n) exp -= n;

        b>>=1;
    }
    return res;
}

// ret = (a^b)%n
bint mod_exp(bint a,bint p,bint m){
    bint exp=a%m, res=1; //
    while(p>1)
    {
        if(p&1)//
            res=muti_mod(res,exp,m);
        exp = muti_mod(exp,exp,m);
        p>>=1;
    }
    return muti_mod(res,exp,m);
}
bool miller_rabin(bint n, int times){
    if(n==2)return 1;
    if(n<2||!(n&1))return 0;

    bint a, u=n-1, x, y;
    int t=0;
    while(u%2==0){
        t++;
        u/=2;
    }
    srand(time(0));
    for(int i=0;i<times;i++){
        a = rand() % (n-1) + 1;
        x = mod_exp(a, u, n);
        for(int j=0;j<t;j++){
            y = muti_mod(x, x, n);
            if ( y == 1 && x != 1 && x != n-1 )
                return false; //must not
            x = y;
        }
        if( y!=1) return false;
    }
    return true;
}

bint pollard_rho(bint n,int c){//找出一个因子
    bint x,y,d,i = 1,k = 2;
    srand(time(0));

    x = rand()%(n-1)+1;
    y = x;
    while(true) {
        i++;
         x = (muti_mod(x,x,n) + c) % n;
        d = gcd(y-x, n);
        if(1 < d && d < n)return d;
         if( y == x)return n;
         if(i == k) {
            y = x;
             k <<= 1;
         }
    }
}
void findFactor(bint n,int k){//二分找出所有质因子，存入factor
    if(n==1)return;

 if(miller_rabin(n, TIME)){
   factor[++fac_top] = n;
  return;
 }
 bint p = n;
 while(p >= n)
  p = pollard_rho(p,k--);//k值变化，防止死循环
 findFactor(p,k);
 findFactor(n/p,k);
}
int su;
bint mi,a;
void dfs(int count,bint x,bint ll){
// printf("%I64d\n",x);
 if(count==su){
  if(x&&mi>x+ll/x){
   mi=x+ll/x;
   a=x;
  }
  return ;
 }
 dfs(count+1,x,ll);
 dfs(count+1,x*aa[count],ll);
}
int main(){
    bint g,l;//g为gcd,l为lcm
    while(scanf("%lld %lld",&g,&l)!=EOF){
  su=0;mi=2e63;fac_top=-1;//x=a*g,y=b*g,x*y=a*g*b*g=g*l,所以a*b=l/g
  findFactor(l/g,107);//将l/g这个数质数分解放入数组factor中
  sort(factor,factor+fac_top);
  aa[0]=factor[0];
  //合并factor中相同的素数，因为l/g=a*b并且gcd(a,b)=1,所以l/g中相同的因子只可能在全在a或者全在b,因此可以将其相乘减少搜索次数
  for(int i=0;i<=fac_top;i++){
   if(factor[i]==factor[i+1])
    aa[su]*=factor[i+1];
   else
    aa[++su]=factor[i+1];
  }
  dfs(0,1,l/g);
  if(a*g<l/a)
   printf("%lld %lld\n",a*g,l/a);
  else
   printf("%lld %lld\n",l/a,a*g);
 }
 return 0;
}
