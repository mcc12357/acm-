#include <iostream>
#include <string.h>
 
int func(int n, int k)
{
    if (n == k)    // �պ������һ����ɱ����
    {
        return k;
    }
    int temp = func(n - n/k, k);        // n���������ɱ��n/k����
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