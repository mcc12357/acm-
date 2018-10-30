#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 11;

int res = 0;    //  ����β��Ҫ�Ĵ���
int res_2 = INF;//  ���м����Ҫ�����ٴ���
int n, a, b;
int H[MAXN];    //  ����ֵ

//  ��������
void dfs(int N, int ans)
{
    //  �������n����ʱ���������ٵı��ƴ�����������
    if (N == n)
    {
        res_2 = res_2 > ans ? ans : res_2;
        return ;
    }
    //  ÿ�����������Ҫ��֤��N-1��Ϊ����
    if (H[N - 1] < 0)
    {
        dfs(N + 1, ans);
    }
    int times = 0;
    //  �����ڵ�Nλ�ñ�times�β��ܱ�֤��N-1��Ϊ����
    if (H[N - 1] >= 0)
    {
        times = H[N - 1] / b + 1;
        H[N - 1] -= b * times;
        H[N] -= a * times;
        H[N + 1] -= b * times;
        dfs(N + 1, ans + times);
        H[N - 1] += b * times;
        H[N] += a * times;
        H[N + 1] += b * times;
    }
    //  ֻҪ��times~times_�ζ��ܱ�֤��N-1��Ϊ����
    int times_ = H[N] / a + 1;
    if (H[N] >= 0 && times_ > times)
    {
        for (int i = times + 1; i <= times_; i++)
        {
            H[N - 1] -= b * i;
            H[N] -= a * i;
            H[N + 1] -= b * i;
            dfs(N + 1, ans + i);
            H[N - 1] += b * i;
            H[N] += a * i;
            H[N + 1] += b * i;
        }
    }

    return ;
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);

    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        cin >> H[i];
    }

    //  �򱬵�1��
    int times = H[1] / b + 1;
    res += times;
    H[1] -= b * times;
    H[2] -= a * times;
    H[3] -= b * times;

    //  �򱬵�n��
    if (H[n] >= 0)
    {
        times = H[n] / b + 1;
        res += times;
        H[n] -= b * times;
        H[n - 1] -= a * times;
        H[n - 2] -= b * times;
    }

    dfs(2, 0);

    //  ��֤res_2����Ч����
    if (res_2 == INF)
    {
        res_2 = 0;
    }

    std::cout << res + res_2 << '\n';
    return 0;
}