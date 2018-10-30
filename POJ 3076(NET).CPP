#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxnode=500010;
const int maxn=4100;
const int maxm=1030;
struct DLX
{
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode],Row[maxnode],Col[maxnode],C[maxm],H[maxn],cnt;
    bool used[maxn];
	int i,j;
    void Init(int n,int m)
    {
        for(i=0;i<=m;i++)
        {
            L[i]=i-1;R[i]=i+1;
            U[i]=D[i]=i;C[i]=0;
        }
        cnt=m;L[0]=m;R[m]=0;

        for(i=1;i<=n;i++)
            H[i]=0,used[i]=false;
    }
    void Link(int x,int y)
    {
        C[Col[++cnt]=y]++;
        Row[cnt]=x;

        U[cnt]=y;
        U[D[y]]=cnt;
        D[cnt]=D[y];
        D[y]=cnt;

        if(H[x])
            L[R[H[x]]]=cnt,R[cnt]=R[H[x]],R[H[x]]=cnt,L[cnt]=H[x];
        else
            H[x]=L[cnt]=R[cnt]=cnt;
    }

    void Delete(int c)
    {
        L[R[c]]=L[c];R[L[c]]=R[c];
        for(i=D[c];i!=c;i=D[i])
            for(j=R[i];j!=i;j=R[j])
                --C[Col[j]],U[D[j]]=U[j],D[U[j]]=D[j];
    }

    void Resume(int c)
    {
        L[R[c]]=c;R[L[c]]=c;
        for(i=U[c];i!=c;i=U[i])
            for(j=L[i];j!=i;j=L[j])
                ++C[Col[j]],U[D[j]]=j,D[U[j]]=j;
    }

    bool Solve()
    {
        if(!R[0])return true;
        int p=R[0];
        for(i=R[p];i;i=R[i])
            if(C[p]>C[i])
                p=i;
        Delete(p);
        for(i=D[p];i!=p;i=D[i]){
            used[Row[i]]=true;
            for(j=R[i];j!=i;j=R[j])
                Delete(Col[j]);
            if(Solve())
                return true;
            used[Row[i]]=false;
            for(j=L[i];j!=i;j=L[j])
                Resume(Col[j]);
        }
        Resume(p);
        return false;
    }
    void Print()
    {
        for(i=1;i<=256;i++){
            for(j=(i-1)*16+1;j<=i*16;j++)
                if(used[j]){
                    int Color=j-(i-1)*16;
                    printf("%c",'A'+Color-1);
                    break;
                }
            if(i%16==0)
                printf("\n");    
        }
        printf("\n");
    }
}DLX;

int Area(int x,int y)
{
    if(x<=4&&y<=4)return 0;
    if(x<=4&&y<=8)return 1;
    if(x<=4&&y<=12)return 2;
    if(x<=4)return 3;
    
    if(x<=8&&y<=4)return 4;
    if(x<=8&&y<=8)return 5;
    if(x<=8&&y<=12)return 6;
    if(x<=8)return 7;
    
    if(x<=12&&y<=4)return 8;
    if(x<=12&&y<=8)return 9;
    if(x<=12&&y<=12)return 10;
    if(x<=12)return 11;
    
    if(y<=4)return 12;
    if(y<=8)return 13;
    if(y<=12)return 14;
    return 15;
}

char str[260],s[17];
int main()
{
    while(true){
        int x=1,y=1,i,j;
        DLX.Init(4096,1024);
        for(i=1;i<256;i+=16){
            if(!~scanf("%s",s))return 0;
            for(j=i;j<i+16;j++)
                str[j]=s[j-i];
        }
        for(i=1;i<=256;i++)
        {
            for(j=(i-1)*16+1;j<=i*16;j++)
            {
                int Color=j-(i-1)*16;
                if(str[i]!='-'&&str[i]-'A'+1!=Color)
                    continue;
    
                DLX.Link(j,(x-1)*16+Color); //行中对应颜色
                DLX.Link(j,256+(y-1)*16+Color); //列中对应颜色 
                DLX.Link(j,512+Area(x,y)*16+Color);//块中对应颜色 
                DLX.Link(j,768+i); //矩阵中对应位置
            }
            y++;x+=y/17;y=(y-1)%16+1;
        }
        DLX.Solve();
        DLX.Print();
    }
    return 0;
}