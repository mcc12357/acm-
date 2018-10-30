#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<set>
using namespace std;
typedef _int64 ll;
ll N;

struct point
{
    double x;
    double y;
	bool operator < (point tm1)
	{
		if(tm1.x==x) return tm1.y<y;
		return tm1.x<x;
	}
}P[100010],res[100010];

set<point> st;
set<point>::iterator it;
int cmp(point a, point b)
{
    if(a.x==b.x)return a.y<b.y;
        return a.x<b.x;
}

double multiply(point sp,point ep,point op)
{
    return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));
}

int convex(int n, point [], point res[])
{
    sort(P, P+n,cmp);
    int m=0,i,j,k;
    //求得下凸包，逆时针
    //已知凸包点m个，如果新加入点为i，则向量(m-2,i)必定要在(m-2,m-1)的逆时针方向才符合凸包的性质
    //若不成立，则m-1点不在凸包上。
    for(i=0;i<n;i++)
    {
        while(m>1&&multiply(res[m-1],P[i],res[m-2])<=0)m--;
        res[m++]=P[i];
    }
    k=m;
    //求得上凸包
    for(i=n-2;i>=0;i--)
    {
        while(m>k&&multiply(res[m-1],P[i],res[m-2])<=0)m--;
        res[m++]=P[i];
    }
    if(n>1)m--;//起始点重复。
    return m;
}


double Max(double a, double b)
{
    return a>b?a:b;
}

int main()
{
    while(scanf("%I64d", &N)!=EOF)
    {
		int i,j,k;
		ll M = N;
		ll ans = 0;
		st.clear();
		//ans = N * (N-1) * (N-2) / 2 / 3;
        for(i=0;i<N;i++)
        {
            scanf("%lf%lf", &P[i].x, &P[i].y);
			it = st.find(P[i]);
			if(it==st.end())
			{
				st.insert(P[i]);
			}
			else
			{
				M--;
			}
        }

        int len = convex(N, P, res);
        double S = 0;
        for(i =0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                for(k=j+1;k<len;k++)
                {
                    //printf("%.2lf\n", multiply( res[i],res[j],res[k] ));
                    S = Max(S, multiply( res[i],res[j],res[k] ) );
                }
            }
        }
		if(M<3) 
		{
			printf("0 %.2lf\n",S*0.5);
		}
		else 
		{
			ans = M * (M-1) * (M-2) / 2 / 3;
			printf("%I64d %.2lf\n",ans,S*0.5);
		}
        //printf("%.2lf\n",S*0.5);

    }
}