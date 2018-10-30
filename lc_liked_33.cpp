#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
	{
		if(nums.empty()) return -1;
        int l = 0,r = nums.size() - 1;
		while(r-l>1)
		{
			int mid = (l + r) / 2;
			if(nums[l]>nums[r])
			{
				if(nums[mid]>nums[l])
				{
					if(target>nums[mid]) l = mid;
					else if(target>=nums[l]) r = mid;
					else l = mid;
				}
				else
				{
					if(target<nums[mid]) r = mid;
					else if(target<=nums[r]) l = mid;
					else r = mid;

				}
			}
			else
			{
				if(target>nums[mid]) l = mid;
				else r = mid;
			}
		}
		if(target==nums[l]) return l;
		else if(target==nums[r]) return r;
		else return -1;
    }
};
int main()
{
	Solution a;
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	//nums.push_back(1);
	//nums.push_back(2);
	int target = 6;
	int res = a.search(nums,target);
	cout<<res<<endl;
}