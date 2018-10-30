#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <cctype>
#include <string>
#include <map>
#include <iostream>
using namespace std;

#define INF 1e9+7
#define MAXN 100010
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int a[15];
int shift(int i,int j)
{
    int s=0;
    for(int k=i;k<=j;k++)
    {
        s=s*10+a[k];
    }
    return s;
}


int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        int minn=INF;
        char temp[30];
        gets(temp);
        int n=(int)strlen(temp);
        int m=0;
        for(int i=0;i<n;i++)
            if(isdigit(temp[i]))
                a[m++]=temp[i]-'0';
        do{
            for(int k=m/2;k<=m/2+1;k++)
            {
                int s1=shift(0, k-1);
                int s2=shift(k, m-1);
                if((s1!=0&&a[0]==0)||(s2!=0&&a[k]==0))
                    continue;
                minn=min(minn,abs(s1-s2));
            }
        }while(next_permutation(a, a+m));
        printf("%d\n",minn);
    }
}