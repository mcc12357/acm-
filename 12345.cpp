#include <iostream>
#include <stdio.h>

using namespace std;

struct D
{
    int x,y;
}dos[1005];

int abs(int a,int b)
{
    if(a>b)
    {
        return(a-b);
    }
    else{return (b-a) ;}
}

int main()
{
    int dx,dy;
    int px,py;
    int quchu1,quchu2;
    int flag,flagy,flagx;
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        dx=1000000;
        dy=1000000;
        int gg=0;
        flag=0;
        flagy=0;
        flagx=0;
        int N,M;
        int ansx,ansy;
        ansx=0;
        ansy=0;
        scanf("%d%d",&N,&M);
        scanf("%d%d",&dos[0].x,&dos[0].y);
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&dos[i].x,&dos[i].y);
            if(dos[i-1].x!=dos[i].x&&dos[i-1].y!=dos[i].y)
            {
                flag=2;
            }
            if(dos[i-1].x==dos[i].x)
            {
                ansy+=abs(dos[i-1].y,dos[i].y);
                flagy=1;
                if(flagx==1)
                {
                    dx=ansx;
                }
                if(dx<M)
                {
                    flag++;
                    if(flagx==1&&gg==0)
                    {
                        quchu1=dx;
                        gg=1;
                    }
                }

                ansx=0;
            }
            if(dos[i-1].y==dos[i].y)
            {
                ansx+=abs(dos[i-1].x,dos[i].x);
                flagx=1;
                if(flagy==1)
                {
                    dy=ansy;
                }
                if(dy<M)
                {
                    flag++;
                    if(flagy==1&&gg==0)
                    {
                        quchu2=dy;
                        gg=1;
                    }
                }

                ansy=0;
            }
        }
        if(dos[N-1].x!=dos[0].x&&dos[N-1].y!=dos[0].y)
        {
            flag++;
        }
        if(gg)
        {
            px=abs(dos[N-1].x,dos[0].x);
            py=abs(dos[N-1].y,dos[0].y);
            if((quchu1+px)>=M||(quchu2+py)>=M)
            {
                flag--;
            }
        }
//         if(dos[N-1].x==dos[0].x)
//        {
//            ansy+=abs(dos[N-1].y,dos[0].y);
//            if(ansx%M!=0)
//            {
//                flag=1;
//            }
//            ansx=0;
//        }
//        if(dos[N-1].y==dos[0].y)
//        {
//            ansx+=abs(dos[N-1].x,dos[0].x);
//            if(ansy%M!=0)
//            {
//                flag=1;
//            }
//            ansy=0;
//        }
        if(flag)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }

    }
}
