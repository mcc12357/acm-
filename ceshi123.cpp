#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
const int MAXN=505;

int vlu[MAXN];
int tim[MAXN][MAXN];
bool view[MAXN]={};
int stim=0;
int stim1=999999;
int ansv=0;
int ansv1=999999;
vector<int>V[MAXN];
queue<int>Q;

void bfs(int s,int e)
{
    if(s==e)
    {
        if(stim<stim1)
        {
            stim1=stim;
        }
        if(stim==stim1)
        {
            if(ansv>ansv1)
            {
                ansv1=ansv;
            }
        }
    }
    else if(!view[s])
    {
        int len;
        len=V[s].size();
        for(int i=0;i<len;i++)
        {
            if(!view[V[s][i]])
            {
                Q.push(V[s][i]);
            }
        }
        view[s]=1;
        if(!Q.empty())
        {
            int r;
            r=Q.front();
            Q.pop();
            stim+=tim[s][r];
            ansv+=vlu[r];
            bfs(r,e);
            ansv-=vlu[r];
            stim-=tim[s][r];
        }

    }
    return ;
}

int main()
{
    int n,m,st,en;
    while(!Q.empty())
    {
        Q.pop();
    }
    while(~scanf("%d%d%d%d",&n,&m,&st,&en))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&vlu[i]);
        }
        ansv=vlu[st];
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            V[x].push_back(y);
            V[y].push_back(x);
            tim[x][y]=z;
            tim[y][x]=z;
        }
        bfs(st,en);
        printf("%d %d",stim1,ansv1);
    }
}
