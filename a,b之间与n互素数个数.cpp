#include<stdio.h>
int prime[20],num;
void suyin(int n)     //��n��������
{
    int i;
      num=0;
        if (n%2==0)     //�Ȱ�ż����������ǣ�����Ϳ���ֻ�ж�������
        {
            prime[num++]=2;
              while(n%2==0) n/=2;
        }
        for (i=3;i*i<=n;i+=2)   
//����n�Ŀ��������������ֻ��һ��������ģ�if (n>1) prime[num++]=n�������ж�����������Ƿ����  
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
                if ((i>>j)&1==1) s=(-1)*s*prime[j];//ÿ�ΰ�λ���ƺ�ȡ���ұ�һλ���ж�
                if ((i>>(j+1))==0) break;      //����Ѿ���0�˵�Ȼ�������ж���
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
               int m=(1<<num);            //����С��num+1λ�Ķ�����������һ��������numλ�Ķ�������
             tot=husu(b,m)-husu(a-1,m);
           printf("%lld\n",tot);
         }
   return 0;
}