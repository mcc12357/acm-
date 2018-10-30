#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
		if(nums.empty()||nums.size()==1) return true;
        bool *dp = new bool[nums.size()];
        int i,j;
        for(i=1;i<nums.size();i++) dp[i] = false;
        dp[0] = true;
        for(i=1;i<nums.size();i++)
        {
            for(j=0;j<i;j++)
            {
                if(dp[j]&&j+nums[j]>=i) 
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};
int main()
{
	Solution a;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	if(a.canJump(nums)) printf("yes\n");
}