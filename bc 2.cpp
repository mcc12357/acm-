#include <cstdio>

int T;
_int64 a, b, c, d;
int ax[70];
int ay[70];

void solve()
{
    int i;
    _int64 sumx = 0;
    _int64 sumy = 0;
    for(i=62; i>=0; i--){
        _int64 tmp = 1;
        tmp <<= i;
        if(tmp+sumx<=b && tmp+sumy>c){
            ax[i] = 1;
            ay[i] = 0;
            sumx += tmp;
        }
        else if(tmp+sumy<=d && tmp+sumx>a){
            ax[i] = 0;
            ay[i] = 1;
            sumy += tmp;
        }
        else if(tmp+sumx<=b && tmp+sumy<=d){
            sumx += tmp;
            sumy += tmp;
        }
    }
    _int64 res = 0;
    res = sumx ^ sumy;
    printf("%I64d\n", res);
}

int main()
{
    int t;
    scanf("%d", &T);
    for(t=0; t<T; t++){
        scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
        solve();
    }
    return 0;
}