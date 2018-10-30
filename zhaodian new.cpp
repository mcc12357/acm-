#include <iostream>
#include <cstdlib>

using namespace std;

int cmp(const void *a, const void *b);

struct data
{
    int l;
    int r;
};

int main()
{
    int n,i;
    data a[105];
    a[0].l = a[0].r = -1;
    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
            cin >> a[i].l >> a[i].r;

        qsort(a+1, n, sizeof(a[0]), cmp);
        int cur = a[0].r;
        int sum = 0;
        for(i = 1; i <= n; i++)
        {
            if(!(cur >= a[i].l && cur <= a[i].r))
            {
                sum++;
                cur = a[i].r;
            }
        }
        cout << sum << endl;
    }
}

int cmp(const void *a, const void *b)
{
    return ((data *)a)->r - ((data *)b)->r;
}
