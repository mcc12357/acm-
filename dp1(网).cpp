#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;

struct Matrix
{
    double mat[2][2];
};
Matrix mul(Matrix a,Matrix b)
{
    Matrix ret;
    for(int i=0;i<2;i++)
      for(int j=0;j<2;j++)
      {
          ret.mat[i][j]=0;
          for(int k=0;k<2;k++)
            ret.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
      }
    return ret;
}
Matrix pow_M(Matrix a,int n)
{
    Matrix ret;
    memset(ret.mat,0,sizeof(ret.mat));
    for(int i=0;i<2;i++)ret.mat[i][i]=1;
    Matrix temp=a;
    while(n)
    {
        if(n&1)ret=mul(ret,temp);
        temp=mul(temp,temp);
        n>>=1;
    }
    return ret;
}

int x[30];
int main()
{
    int n;
    double p;
    while(scanf("%d%lf",&n,&p)!=EOF)//POJ上G++要改为cin输入
    {
		int i;
        for(i=0;i<n;i++)
          scanf("%d",&x[i]);
        sort(x,x+n);
        double ans=1;
        Matrix tt;
        tt.mat[0][0]=p;
        tt.mat[0][1]=1-p;
        tt.mat[1][0]=1;
        tt.mat[1][1]=0;
        Matrix temp;

        temp=pow_M(tt,x[0]-1);
        ans*=(1-temp.mat[0][0]);

        for(i=1;i<n;i++)
        {
            if(x[i]==x[i-1])continue;
            temp=pow_M(tt,x[i]-x[i-1]-1);
            ans*=(1-temp.mat[0][0]);
        }
        printf("%.7lf\n",ans);//POJ上G++要改为%.7f
    }
    return 0;
}