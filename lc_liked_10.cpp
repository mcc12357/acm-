#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
class Solution 
{
public:
    bool isMatch(string s, string p) 
	{
        if(p.empty()) return s.empty();
		bool flag = (!s.empty() && (s[0]==p[0] || p[0]=='.') );
		if(p.size()>=2 && p[1]=='*') 
		{
			string pSubstring,sSubstring;
			int i;
			for(i=2;i<p.size();i++) pSubstring += p[i];
			for(i=1;i<s.size();i++) sSubstring += s[i];
			return isMatch(s,pSubstring) || flag && isMatch(sSubstring,p);
		}
		else
		{
			string pSubstring,sSubstring;
			int i;
			for(i=1;i<p.size();i++) pSubstring += p[i];
			for(i=1;i<s.size();i++) sSubstring += s[i];
			return flag && isMatch(sSubstring,pSubstring);
		}

    }
};
int main()
{
	Solution a;
	string s = "ab";
	string p = ".*c";
	bool res = a.isMatch(s,p);
	if(res) printf("true\n");
	else printf("false\n");
}