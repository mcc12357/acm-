//Memory Time 
//656K  16MS 

/*���ر���+�������Ż�*/

#include<iostream>
using namespace std;
#include<string.h>

int n[7];  //��ֵΪi����Ʒ�ĸ���
int v;  //��������
int SumValue;  //��Ʒ�ܼ�ֵ
bool flag;    //����Ƿ���ƽ��SumValue
int dp[100000];  //״̬����

int max(int a,int b)
{
    return a>b?a:b;
}

/*��ȫ����*/
void CompletePack(int cost,int weight)
{
    for(int i=cost;i<=v;i++)
    {
        dp[i]=max(dp[i],dp[i-cost]+weight);
        if(dp[i]==v)    //��֦�����ܹ�ƽ��SumValueʱ�˳�
        {
            flag=true;
            return;
        }
    }
            
    return;
}

/*01����*/
void ZeroOnePack(int cost,int weight)
{
    for(int i=v;i>=cost;i--)
    {
        dp[i]=max(dp[i],dp[i-cost]+weight);
        if(dp[i]==v)    //��֦
        {
            flag=true;
            return;
        }
    }
    return;
}

/*���ر���*/
void MultiplePack(int cost,int weight,int amount)
{
    if(cost*amount>=v)
    {
        CompletePack(cost,weight);
        return;
    }

    if(flag)    //��֦
        return;

    /*�������Ż�*/
    int k=1;
    while(k<amount)
    {
        ZeroOnePack(k*cost,k*weight);

        if(flag)    //��֦
            return;

        amount-=k;
        k*=2;
    }
    ZeroOnePack(amount*cost,amount*weight);

    return;
}

int main(int i)
{
    int test=1;
    while(cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]>>n[6])
    {
        SumValue=0;  //��Ʒ�ܼ�ֵ

        for(i=1;i<=6;i++)
            SumValue+=i*n[i];

        if(SumValue==0)
            break;

        if(SumValue%2)    //sumΪ�������޷�ƽ��
        {
            cout<<"Collection #"<<test++<<':'<<endl;
            cout<<"Can't be divided."<<endl<<endl;    //ע���п���
            continue;
        }

        v=SumValue/2;
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        flag=false;

        for(i=1;i<=6;i++)
        {
            MultiplePack(i,i,n[i]);

            if(flag)    //��֦
                break;
        }

        if(flag)
        {
            cout<<"Collection #"<<test++<<':'<<endl;
            cout<<"Can be divided."<<endl<<endl;
            continue;
        }
        else
        {
            cout<<"Collection #"<<test++<<':'<<endl;
            cout<<"Can't be divided."<<endl<<endl;
            continue;
        }
    }
    return 0;
}