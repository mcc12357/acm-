#include<iostream>
using namespace std;
#include<stdio.h>
int abs(int x)
{
    if(x<0) return -x;
    return x;
}
class Solution {
public:
    int reverse(int x) {
        _int64 sum = 0;
        _int64 times = 1;
        int i = 0;
        int a[20];
        bool flag;
        if(x>0) flag = true;
        else flag = false;
        x = abs(x);
        while(x)
        {
            a[i] = x % 10;
            i++;
            x /= 10;
        }
        i--;
		int n = i;
        while(i>=0)
        {
            sum += a[i] * times;
            times *= 10;
            i--;
        }
        if(!flag) sum = -sum;
		int intmax = oxffffffff;//
		int intmin = 0x80000000;//����д�����У�������16���Ʊ�ʾ���йأ����ֱ�����ڱȽϽ�����󣬱�����ʮ�������ֱ�ʾ
        if( (sum>(2147483647)) || (sum<-2147483647-1 )) return 0;
        return sum;
    }
};
int main()
{
	Solution a;
	int x = 1534236469;
	int res = a.reverse(x);
	printf("%d\n",res);
}