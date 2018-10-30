#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<string>
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
	{
		if(strs.size()==0) return "";
		if(strs.size()==1) return strs[0];
		int i,j,k;
        int index = strs[0].size() - 1;
		for(i=1;i<strs.size();i++)
		{
			for(j=0;j<=index&&j<strs[i].size();j++)
			{
				if(strs[0][j]!=strs[i][j]) break;
			}
			index = j - 1;
			if(index==-1) return "";
		}
		string s;
		for(i=0;i<=index;i++) s += strs[0][i];
		return s;
    }
};
int main()
{
	Solution a;
	vector<string> strs;
	strs.push_back("c");
	strs.push_back("c");
	string res = a.longestCommonPrefix(strs);
	cout<<res<<endl;
	
}