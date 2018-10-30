#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 30;
int n,m,k;
typedef struct matrix
{
    int a[maxn][maxn],r;
    matrix(int rr):r(rr)
    {
        for(int i=0;i<r;++i)//初始化成e矩阵
            for(int j=0;j<r;++j)
                if(i==j) a[i][i]=1;
                else a[i][j]=0;
    }
    void m0()//变成0矩阵
    {
        for(int i=0;i<r;++i)
            for(int j=0;j<r;++j)
                a[i][j] = 0;
    }
}mat;
mat e(30);//identity matrix
mat operator *(const mat & a,const mat &b)//重载*运算符
{
    mat c(n);
    c.m0();
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(a.a[i][j])
                for(int l=0;l<n;++l)
                    c.a[i][l] = (c.a[i][l]+a.a[i][j]*b.a[j][l])%m;
    return c;
}
mat operator +(const mat & a,const mat &b)//重载+运算符
{
    mat c(n);
    c.m0();
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            c.a[i][j] = (a.a[i][j]+b.a[i][j])%m;
    return c;
}

mat Pow(mat a,int t)//矩阵快速幂
{
    mat res(n);//res存储结果，初始化为e矩阵
    while(t)
    {
        if(t & 1) res = a*res;
        a = a*a;
        t>>=1;
    }
    return res;
}
mat solve(mat a,int k)//等比数列二分求和
{
    if(k==1)
        return a;
    if(k & 1)
        return Pow(a,k)+solve(a,k-1);//当n是奇数,f[n]=f[n-1]+A^(n);
    else
        return solve(a,k>>1)*(Pow(a,k>>1)+e);//当n是偶数,f[n]=f[n/2]*(A^(n/2)+E);
}

int main()
{
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
		int i,j;
        mat a(n);
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                scanf("%d",&a.a[i][j]);

        mat ans(n);
        ans = solve(a,k);

        //输出答案
		
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                printf("%d%c",ans.a[i][j],((j==n-1)?'\n':' '));
    }
    return 0;
}
