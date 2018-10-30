#include<stdio.h>
int pri[100],rc[100];
void ou(int n)//求出所有的素因子，任何一个合数都能化成素数的幂次方的形式
{
    int i,j=0;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
            pri[++j]=i;
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        pri[++j]=n;
    pri[0]=j;
}
void rongchi()
{
    int i,j,t=1,t1;
    rc[1]=1;
    for(i=1; i<=pri[0]; i++)
    {
        t1=t;
        for(j=1; j<=t1; j++)
            rc[++t]=rc[j]*pri[i]*-1;//注意乘以-1，当有相同的时候说明前面减去的多了再乘一次变成相加
        t1=t;
    }
    rc[0]=t;
}
int judge(int m)//利用容斥原理求出【1-m】中有多少个与n互素的元素
{
    int sum=m,i;
    for(i=2; i<=rc[0]; i++)
        sum+=m/rc[i];
    return sum;
}
int Bernery(int n,int m)//二分求出第k个互质数
{
    int x=1,y=2000000000;
    while(x<y)
    {
        int temp=(x+y)/2,ss=judge(temp);
        if(m<=ss)
            y=temp;
        else
            x=temp+1;
    }
    return x;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ou(n);
        rongchi();
        printf("%d\n",Bernery(n,m));
    }
    return 0;
}