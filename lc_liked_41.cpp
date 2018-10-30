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
    int firstMissingPositive(int nums[]) 
    {
        int i = 0;
        while(i<4)
        {
            if(nums[i]!=i+1&&nums[i]<=4&&nums[i]>=1) swap(nums[i],nums[nums[i]-1]); 
			else i++;
        }
        for(i=0;i<4;i++)
        {
            if(nums[i]!=i+1) break;
        }
        return i+1;
    }
};
int main()
{
	Solution a;
	int nums[4];
	nums[0] = 3;
	nums[1] = 4;
	nums[2] = -1;
	nums[3] = 1;
	int res = a.firstMissingPositive(nums);
	cout<<res<<endl;
}