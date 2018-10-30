#include <iostream>
#include <string.h>
 
int func(int n, int k)
{
    if (n == k)    // 刚好是最后一个被杀的人
    {
        return k;
    }
    int temp = func(n - n/k, k);        // n个人里可以杀掉n/k个人
    return (temp - 1) / (k - 1) + temp;
}
 
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", func(n, k));
    }
 
    system("pause");
    return 0;
}