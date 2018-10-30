#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
class Solution 
{
public:
	vector<vector<int> > res;
	void dfs(int num,int x,vector<int> nums,bool *used,vector<int> tmp)
	{
		if(num==nums.size())
		{
			res.push_back(tmp);
			return ;
		}
		int i;
		set<int> s;
		s.clear();
		for(i=0;i<nums.size();i++)
		{
			if(used[i]) continue;
			if(s.find(nums[i])!=s.end()) continue;
			s.insert(nums[i]);
			tmp.push_back(nums[i]);
			used[i] = true;
			dfs(num+1,i,nums,used,tmp);
			used[i] = false;
			tmp.pop_back();
		}
	}
    vector<vector<int> > permuteUnique(vector<int>& nums) 
	{
        sort(nums.begin(),nums.end());
		int i;
        for(i=0;i<res.size();i++) res.clear();
		bool *used = new bool[nums.size()];
		set<int> s;
		s.clear();
		for(i=0;i<nums.size();i++)
		{
			if(s.find(nums[i])!=s.end()) continue;
			s.insert(nums[i]);
			vector<int> tmp;
			tmp.clear();
			memset(used,0,sizeof(used));
			used[i] = true;
			tmp.push_back(nums[i]);
			dfs(1,i,nums,used,tmp);
		}
		return res;
    }
};

int main()
{
	Solution a;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(4);
	vector<vector<int> > res = a.permuteUnique(nums);
	int i,j;
	for(i=0;i<res.size();i++)
	{
		for(j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<' ';
		}
		cout<<endl;
	}

}