#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
class Solution {
public:
    vector<vector<string> > dic = vector<vector<string> >(26,vector<string>(100));
    bool judge(string &s,int x,string t)
    {
		int i;
        for(i=0;i<t.size();i++)
        {
            if(x+i<s.size()&&s[x+i]==t[i]) continue;
            else return false;
        }
        return true;
    }
    bool dfs(int x,string &s,bool *is_composed)
    {
		int i;
        if(x>=s.size()) return true;
        if(is_composed[x]) return true;
        for(i=0;i<dic[s[x]-'a'].size();i++)
        {
            if(judge(s,x,dic[s[x]-'a'][i])&&dfs(x+dic[s[x]-'a'][i].size()+1,s,is_composed))
            {
                is_composed[x] = true;
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
		int i;
        if(wordDict.empty()) return false;
        for(i=0;i<wordDict.size();i++)
        {
            dic[wordDict[i][0]-'a'].push_back(wordDict[i]);
        }
        bool *is_composed = new bool [s.size()];
        for(i=0;i<s.size();i++) is_composed[i] = false;
        return dfs(0,s,is_composed);
    }
};
int main()
{
	Solution a;
	string s = "leetcode";
	vector<string> word;
	word.push_back("leet");
	word.push_back("code");
	if(a.wordBreak(s,word)) cout<<"yes"<<endl;
}