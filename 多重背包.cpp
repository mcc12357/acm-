#include <iostream>   
using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
} 
  
const int N = 3;//物品个数   
const int V = 8;//背包容量   
int Weight[N + 1] = {0,1,2,2};  
int Value[N + 1] = {0,6,10,20};  
int Num[N + 1] = {0,10,5,2};  
  
int f[V + 1] = {0};  
/* 
f[v]:表示把前i件物品放入容量为v的背包中获得的最大收益。 
f[v] = max(f[v],f[v - Weight[i]] + Value[i]); 
v的为逆序 
*/  
void ZeroOnePack(int nWeight,int nValue)  
{  
    for (int v = V;v >= nWeight;v--)  
    {  
        f[v] = max(f[v],f[v - nWeight] + nValue);  
    }  
}  
  
/* 
f[v]:表示把前i件物品放入容量为v的背包中获得的最大收益。 
f[v] = max(f[v],f[v - Weight[i]] + Value[i]); 
v的为增序 
*/  
void CompletePack(int nWeight,int nValue)  
{  
    for (int v = nWeight;v <= V;v++)  
    {  
        f[v] = max(f[v],f[v - nWeight] + nValue);  
    }  
}  
  
int MultiKnapsack()  
{  
    int k = 1;  
    int nCount = 0;  
    for (int i = 1;i <= N;i++)  
    {  
        if (Weight[i] * Num[i] >= V)  
        {  
            //完全背包:该类物品原则上是无限供应，   
            //此时满足条件Weight[i] * Num[i] >= V时，   
            //表示无限量供应，直到背包放不下为止.   
            CompletePack(Weight[i],Value[i]);  
        }  
        else  
        {  
            k = 1;  
            nCount = Num[i];  
            while(k <= nCount)  
            {  
                ZeroOnePack(k * Weight[i],k * Value[i]);  
                nCount -= k;  
                k *= 2;  
            }  
            ZeroOnePack(nCount * Weight[i],nCount * Value[i]);  
        }  
    }  
    return f[V];  
}  
  
int main()  
{  
    cout<<MultiKnapsack()<<endl;  
    //system("pause");  
    return 1;  
}  