#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
int abs(int x)
{
	return x>0?x:-x;
}
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
	{
        sort(nums.begin(),nums.end());
		int res = abs(nums[0]+nums[1]+nums[2]-target);
		int ans = nums[0]+nums[1]+nums[2];
		int i,j;
		for(i=0;i<nums.size();i++)
		{
			if(i>=1 && nums[i]==nums[i-1]) continue;
			int l,r;
			for(j=i+1;j<nums.size();j++)
			{
				if(j!=i+1 && nums[j]==nums[j-1]) continue;
				l = j + 1;
				r = nums.size() - 1;
				int need = target - (nums[i] + nums[j]);
				while(r-l>1&&l<nums.size()&&l>j&&r<nums.size()&&r>j)
				{
					int mid = (l + r) / 2;
					if(nums[mid]<=need) l = mid;
					else r = mid;
				}
				if(l<nums.size()&&l>j&&abs(need-nums[l])<res) 
				{
					res = abs(need-nums[l]);
					ans = (nums[i]+nums[j]+nums[l]);
				}
				if(r<nums.size()&&r>j&&abs(need-nums[r])<res)
				{
					res = abs(need-nums[r]);
					ans = (nums[i]+nums[j]+nums[r]);
				}
			}
		}
		return ans;
    }
};
int main()
{
	Solution a;
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(-4);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(-4);
	nums.push_back(-2);
	nums.push_back(-8);
	int ans = a.threeSumClosest(nums,-20);
	cout<<ans<<endl;
}