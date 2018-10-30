#include<iostream>
#include<string.h>
using namespace std;
int pp[510][510];
int map[510] , vis[510];
int k,w,m;
int find_path(int x)
{
     for(int i=1;i<=m;i++)
     {
         if(!vis[i] && pp[x][i])
         {
            vis[i]=1;
            if(!map[i] || find_path(map[i]))
            {
                map[i]=x;
                return 1;
            }
         }
     }
     return 0;
}
int main()
{
    int a,b;
    int sum;
    while(scanf("%d",&k)!=EOF && k)
    {
        scanf("%d%d",&w,&m);
        memset(pp,0,sizeof(pp));
        memset(map,0,sizeof(map));
        sum=0;
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&a,&b);
            pp[a][b]=1;
        }
        for(int j=1;j<=w;j++)
        {
            memset(vis,0,sizeof(vis));
            if(find_path(j))  sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
} 
