#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
	{
		int i;
        bool islast = true;
		if(islast)
		{
			for(i=0;i<nums.size();i++) 
			{
				int n = nums.size();
				int j;
				//if(i==0) nums.insert(nums.begin()+i,nums[nums.end()-nums.begin()-1]);
				//else nums.insert(nums.begin()+i,nums[nums.end()-nums.begin()]);
				//if(i==0) nums.insert(nums.begin()+i,nums[nums.size()-1]);
				//else nums.insert(nums.begin()+i,nums[nums.size()]);
				nums.insert(nums.begin()+i,nums.back()+0);
				n = nums.size();
				nums.pop_back();
				n = nums.size();
				//for(j=0;j<=nums.size()+1;j++) cout<<nums[j]<<endl;
			}
		}
    }
};
int main()
{
	Solution a;
	vector<int> nums;
	int i;
	for(i=0;i<8;i++) nums.insert(nums.begin()+i,8-i-1);
	for(i=0;i<nums.size();i++) cout<<nums[i]<<endl;
	a.nextPermutation(nums);
	for(i=0;i<nums.size();i++) cout<<nums[i]<<endl;
}