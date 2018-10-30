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
		for(i=x+1;i<candidates.size();i++)
		{
            if( i>x+1&&candidates[i]==candidates[i-1]) continue;
			ans.push_back(candidates[i]);
			dfs(i,target-candidates[i],candidates,ans);
			ans.pop_back();
		}
	}
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) 
	{
		int i;
		for(i=0;i<res.size();i++) res[i].clear();
        sort(candidates.begin(),candidates.end());
		vector<int> tmp;
		for(i=0;i<candidates.size();i++)
		{
			tmp.clear();
            if(i>0&&candidates[i]==candidates[i-1]) continue;
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
	candidates.push_back(10);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	res = a.combinationSum2(candidates,8);
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