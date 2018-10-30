#include<iostream>
using namespace std;
#include<stdio.h>
class Solution 
{
public:
    int divide(int dividend, int divisor) 
	{
		if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		int res = 0;
		while(dvd>=dvs)
		{
			int k = 0;
			while( (dvs<<k) <=dvd) k++;
			k--;
			res += 1<<k;
			dvd -= dvs<<k;
		}
		return sign == 1 ? res : -res;
    }
};
int main()
{
	int dividend = 1;
	int divisor = 1;
	Solution a;
	int res = a.divide(dividend,divisor);
	cout<<res<<endl;
}