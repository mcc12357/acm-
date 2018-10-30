#include<stdio.h>
int prime[20],num;
void suyin(int n)     //求n的质因子
{
    int i;
      num=0;
        if (n%2==0)     //先把偶数的情况考虑，下面就可以只判断奇数了
        {
            prime[num++]=2;
              while(n%2==0) n/=2;
        }
        for (i=3;i*i<=n;i+=2)   
//大于n的开方的质因子最多只有一个，下面的（if (n>1) prime[num++]=n）就是判断这个质因子是否存在  
        {
            if (n%i==0)
            {
                prime[num++]=i;
                while (n%i==0) n/=i;
            }
        }
        if (n>1) prime[num++]=n;   
}
long long husu(long long a,int m)
{
   long s,sum;
   int i,j;
     sum=a;
       for (i=1;i<m;i++)
        {
          s=1;
            for (j=0;j<num;j++)
              {
                if ((i>>j)&1==1) s=(-1)*s*prime[j];//每次按位右移后取最右边一位数判断
                if ((i>>(j+1))==0) break;      //如果已经是0了当然不用再判断了
              }
           sum=sum+a/s;
        }
    return sum;
}
int main()
{
   long long a,b,tot;
   int n,t,k=1,i;
     scanf("%d",&t);
       while (t--)
         {
           scanf("%lld%lld%d",&a,&b,&n);
             suyin(n);
               int m=(1<<num);            //求最小的num+1位的二进制数，减一后就是最大num位的二进制数
             tot=husu(b,m)-husu(a-1,m);
           printf("%lld\n",tot);
         }
   return 0;
}