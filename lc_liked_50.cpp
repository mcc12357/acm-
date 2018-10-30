#include<iostream>
using namespace std;
#include<stdio.h>
class Solution 
{
public:
	double abs(double x) {return x>0?x:-x;}
    double myPow(double x, int n) 
	{
		double res = 1;
        if(n==0) return 1.0;
		if (n == INT_MIN)
		{
			n++;
			res *= x;
		}
		if(n<0) 
		{
			x = 1.0 / x;
			n = -n;
		}
		while(n)
		{
			if(n%2) 
			{
				res *= x;
			}
			x *= x;
			n >>= 1;
		}
		return res;
    }
};
int main()
{
	Solution a;
	double res = a.myPow(1.00012,1024);
	cout<<res<<endl;
}