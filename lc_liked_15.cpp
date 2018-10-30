#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
//time limited,可能是vector那里写的不好，算法应该是对的
class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int>& nums) 
	{
        int i,l,r,k = 0;
		int *a = new int[nums.size()];
		for(i=0;i<nums.size();i++) a[i] = nums[i];
		sort(a,a+nums.size());
		vector<vector<int> > res(nums.size()*(nums.size()-1)*(nums.size()-2),vector<int>(3));
		for(i=0;i<res.size();i++) res[i].clear();
 		for(i=0;i<nums.size();i++)
		{
			if(i>=1 && a[i]==a[i-1]) continue;
			if(a[i]>0) break;
			if(a[nums.size()-1]<0) break;
			l = i + 1;
			r = nums.size() - 1;
			int need = -(a[i]);
			while(r>l && l>i && l<nums.size() && r>i && r<nums.size())
			{
				if(a[l]+a[r]==need && (l!=i+1 && a[l]!=a[l-1] || l==i+1))
				{
					res[k].push_back(a[i]);
					res[k].push_back(a[l]);
					res[k].push_back(a[r]);
					k++;
					l++;
					r--;
				}
				else if(a[l]+a[r]<need)
				{
					l++;
				}
				else r--;
			}
		}
		res.resize(k);
		return res;
    }
};
int main()
{
	Solution a;
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	vector<vector<int> > res = a.threeSum(nums);
	int i,j;
	for(i=0;i<res.size();i++)
	{
		for(j=0;j<res[i].size();j++) printf("%d",res[i][j]);
		printf("\n");
	}
}