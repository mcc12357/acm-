#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
int stoi(string s)
{
	int i;
	int res = 0;
	for(i=0;i<s.size();i++)
	{
		res = res * 10 + s[i] - '0'; 
	}
	return res;
}
class Solution {
public:
    vector<string> res;
    void dfs(int start,int end,string &tmp,string &s,int num)
    {
        if(num==4)
        {
            if(end==s.size()-1)
            {
                res.push_back(tmp);
            }
            return ;
        }
        if(s.size()-end-1<4-num||(s.size()-end-1)>3*(4-num)) return ;
        int i;
        int newstart = end + 1;
        if(s[newstart]=='0')
        {
            tmp += s.substr(newstart,1);
            if(num+1<4) tmp += '.';
            dfs(newstart,newstart,tmp,s,num+1);
            if(num+1<4) tmp.erase(tmp.size()-1);
            tmp.erase(tmp.size()-1,1);
            return ;
        }
        for(i=0;i<3;i++)
        {
            int newend = newstart+i;
            if(newend<s.size())
            {
                int x = stoi(s.substr(newstart,i+1));
                if(x>0&&x<=255)
                {
                    tmp += s.substr(newstart,i+1);
                    if(num+1<4) tmp += '.';
                    dfs(newstart,newend,tmp,s,num+1);
                    if(num+1<4) tmp.erase(tmp.size()-1);
                    tmp.erase(tmp.size()-i-1,i+1);
                }
                
            }
        }
    }
    vector<string> restoreIpAddresses(string s) 
    {
        res.clear();
        if(s.size()>12||s.size()<4) return res;
        int i;
        for(i=0;i<3;i++)
        {
            string tmp = "";
            tmp += s.substr(0,i+1);
            tmp += '.';
			if(s[0]=='0')
			{
				dfs(0,i,tmp,s,1);
				break;
			}
            int x = stoi(s.substr(0,i+1));
            if(i<s.size()&&x>0&&x<=255) dfs(0,i,tmp,s,1);
        }
        return res;
    }
};
int main()
{
	Solution a;
	string s = "0000";
	vector<string> res;
	res = a.restoreIpAddresses(s);
	int i;
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
}