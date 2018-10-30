#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
class Solution 
{
public:
    struct node
    {
        int maxindex;
        int step;
        node(int x,int y):maxindex(x),step(y){}
        bool operator < (const node &x) const
        {
            if(x.step==step) return x.maxindex>maxindex;
            return x.step<step;
        }
    };
    int jump(vector<int>& nums) 
    {
        priority_queue<node> q;
        int i;
        while(!q.empty()) q.pop();
        int *dp = new int[nums.size()];
        dp[0] = 0;
        node t(nums[0],0);
        //int farreach = nums[0];
        q.push(t);
        for(i=1;i<nums.size();i++)
        {
            if(i<=t.maxindex) 
            {
                dp[i] =  t.step + 1;
                if(i+nums[i]>t.maxindex) q.push(node(i+nums[i],dp[i]));
            }
            else
            {
                while(!q.empty()&&i>t.maxindex) 
                {
                    t = q.top();
                    q.pop();
                }
                dp[i] =  t.step + 1;
                if(i+nums[i]>t.maxindex) q.push(node(i+nums[i],dp[i]));
            }
        }
        return dp[nums.size()-1];
    }
};