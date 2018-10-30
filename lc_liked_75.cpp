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
    void sortColors(int nums[]) 
    {
        //if(!nums.size()||nums.size()==1) return ;
        int t1 = 0,t2 = 0,t3 = 6 - 1;
        while(t2<=t3)
        {
            if(nums[t2]==0) 
            {
                swap(nums[t1],nums[t2]);
                t1++;
                t2++;
            }
            else if(nums[i]==1) t2++;
            else
            {
                swap(nums[t2],nums[t3]);
                t3--;
            }
        }
    }
};
int main()
{
	int nums[6];
	nums[0] = 2;
	nums[1] = 0;
	nums[2] = 2;
	nums[3] = 1;
	nums[4] = 1;
	nums[5] = 0;
	Solution a;
	a.sortColors(nums);
	int i;
	for(i=0;i<6;i++) cout<<nums[i]<<endl;
}