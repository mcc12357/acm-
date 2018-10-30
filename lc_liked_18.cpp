#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
class Solution 
{
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
	{
        sort(nums.begin(),nums.end());
		int i,j,l,r;
		vector<vector<int> > res;
		for(i=0;i<nums.size();i++)
		{
			if(i>=1&&nums[i]==nums[i-1]) continue;
			for(j=i+1;j<nums.size();j++)
			{
				if(j!=i+1&&nums[j]==nums[j-1]) continue;
				l = j + 1;
				r = nums.size() - 1;
				int need = target - (nums[i] + nums[j]);
				while(r>l&&l<nums.size()&&l>j&&r<nums.size()&&r>j)
				{
					if(l>j+1 && nums[l]==nums[l-1]) 
					{
						l++;
						continue;
					}
					if(r<nums.size()-1 && nums[r]==nums[r+1]) 
					{
						r--;
						continue;
					}
					if(need==nums[l]+nums[r])
					{
						/*vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[l]);
						tmp.push_back(nums[r]);
						res.push_back(tmp);*/
						res.push_back({nums[i],nums[j],nums[l],nums[r]});
						l++;
						r--;
						continue;
					}
					if(need>nums[l]+nums[r]) l++;
					if(need<nums[l]+nums[r]) r--;
				}
			}
		}
		return res;
    }
};
int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(-5);
	nums.push_back(-2);
	nums.push_back(-2);
	nums.push_back(-4);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(-2);
	Solution a;
	vector<vector<int> > res;
	res = a.fourSum(nums,-9);
	int i,j;
	for(i=0;i<res.size();i++)
	{
		for(j=0;j<res[i].size();j++) cout<<res[i][j];
		cout<<endl;
	}
}