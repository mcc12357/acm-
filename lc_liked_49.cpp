#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<string>
class Solution 
{
public:
	vector<vector<string> > res;
    vector<vector<string> > groupAnagrams(vector<string>& strs) 
	{
        int i,j,k;
		for(i=0;i<res.size();i++) res[i].clear();
		int **num = new int*[strs.size()];
		for(i=0;i<strs.size();i++) 
		{
			num[i] = new int[26];
			for(j=0;j<26;j++) num[i][j] = 0;
			for(j=0;j<strs[i].size();j++) num[i][strs[i][j]-'a']++;
		}
		bool *used = new bool[strs.size()];
		for(i=0;i<strs.size();i++) used[i] = false;
		for(i=0;i<strs.size();i++)
		{
			if(used[i]) continue;
			used[i] = true;
			vector<string> tmp;
			tmp.clear();
			tmp.push_back(strs[i]);
			for(j=i+1;j<strs.size();j++)
			{
				if(used[j]) continue;
				for(k=0;k<26;k++)
				{
					if(num[i][k]!=num[j][k]) break;
				}
				if(k==26)
				{
					tmp.push_back(strs[j]);
					used[j] = true;
				}
			}
			res.push_back(tmp);
		}
		return res;
    }
};
int main()
{
	vector<string> strs;
	Solution a;
	string tmp = "";
	strs.push_back(tmp);
	tmp = "";
	strs.push_back(tmp);
	tmp = "apple";
	strs.push_back(tmp);
	tmp = "bad";
	strs.push_back(tmp);
	tmp = "dab";
	strs.push_back(tmp);
	vector<vector<string> > res = a.groupAnagrams(strs);
	int i,j;
	//for(i=0;i<strs.size();i++) cout<<strs[i]<<endl;
	for(i=0;i<res.size();i++)
	{
		for(j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}