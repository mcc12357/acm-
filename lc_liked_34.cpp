#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> res;
		res.clear();
		if(nums.empty())
		{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
        int l = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
		int r = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
		if(nums[l]==target) 
		{
			res.push_back(l);
			res.push_back(r-1);
			return res;
		}
		else
		{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
    }
};
int main()
{
	Solution a;
	vector<int> res;
	vector<int> nums;
	nums.push_back(-1);
	res = a.searchRange(nums,0);
	int i;
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
}