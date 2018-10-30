#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
	{
        int i;
		int n = nums.size();
		for(i=0;i<n;i++)
		{
			if(i>0 && nums[i]==nums[i-1])
			{
				nums.erase(nums.begin()+i);
				n--;
				i--;
			}
		}
		return nums.size();
    }
};
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);
	Solution a;
	int res = a.removeDuplicates(nums);
	cout<<res<<endl;
}