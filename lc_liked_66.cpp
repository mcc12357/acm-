#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
	{
        int i;
		int carry = 1;
		for(i=digits.size()-1;i>=0;i--)
		{
			int tmp = digits[i] + carry;
			digits[i] = tmp % 10;
			carry = tmp / 10;
			if(!carry) break;
		}
		if(carry) digits.insert(digits.begin(),1);
		return digits;
    }
};
int main()
{
	Solution a;
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(2);
	vector<int> res;
	res = a.plusOne(digits);
	int i;
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
}