#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
class Solution 
{
public:
	vector<vector<int> > res;
	void dfs(int x,int target,vector<int>& candidates,vector<int>& ans)
	{
		if(target==0) 
		{
			res.push_back(ans);
			return ;
		}
		if(target<0) return ;
		int i;
		for(i=x;i<candidates.size();i++)
		{
			ans.push_back(candidates[i]);
			dfs(i,target-candidates[i],candidates,ans);
			ans.pop_back();
		}
	}
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
	{
		int i;
		for(i=0;i<res.size();i++) res[i].clear();
		vector<int> tmp;
		for(i=0;i<candidates.size();i++)
		{
			tmp.clear();
			tmp.push_back(candidates[i]);
			dfs(i,target-candidates[i],candidates,tmp);
		}
		return res;
    }
};
int main()
{
	Solution a;
	vector<vector<int> > res;
	vector<int> candidates;
	//candidates.push_back(2);
	//candidates.push_back(3);
	//candidates.push_back(5);
	//candidates.push_back(7);
	res = a.combinationSum(candidates,8);
	int i,j;
	for(i=0;i<res.size();i++)
	{
		for(j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}