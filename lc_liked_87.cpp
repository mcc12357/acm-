#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
class Solution 
{
public:
    bool judge(string &s1,int start1,string &s2,int start2,int len)
    {
        if(len==0) return s1[start1]==s2[start2];
        int i;
        for(i=0;i<=len;i++)
        {
            if(s1[start1+i]!=s2[start2+i]) break;
        }
        if(i==len+1) return true;
        map<char,int> m1;
        map<char,int> m2;
        m1.clear();
        m2.clear();
        for(i=0;i<=len;i++)
        {
            if(m1.find(s1[start1+i])==m1.end()) m1[s1[start1+i]] = 1;
            else m1[s1[start1+i]]++;
            if(m2.find(s2[start2+i])==m2.end()) m2[s2[start2+i]] = 1;
            else m2[s2[start2+i]]++;
        }
        map<char,int>::iterator it;
        for(it=m1.begin();it!=m1.end();it++)
        {
            if(m2[it->first]!=it->second) return false;
        }
        for(i=0;i<len;i++)
        {
            if(judge(s1,start1,s2,start2,i)&&judge(s1,start1+i+1,s2,start2+i+1,len-i-1) || 
               judge(s1,start1,s2,start2+len-i,i)&&judge(s1,start1+i+1,s2,start2,len-i-1)) return true;
        }
        return false;
    }
    bool isScramble(string s2, string s1) 
    {
        if(s1.size()!=s2.size()) return false;
        int n = s1.size();
        int i;
        map<char,int> m1;
        map<char,int> m2;
        m1.clear();
        m2.clear();
        for(i=0;i<n;i++)
        {
            if(s1[i]!=s2[i]) break;
        }
        if(i==n) return true;
        for(i=0;i<n;i++)
        {
            if(m1.find(s1[i])==m1.end()) m1[s1[i]] = 1;
            else m1[s1[i]]++;
            if(m2.find(s2[i])==m2.end()) m2[s2[i]] = 1;
            else m2[s2[i]]++;
        }
        map<char,int>::iterator it;
        for(it=m1.begin();it!=m1.end();it++)
        {
            if(m2[it->first]!=it->second) return false;
        }
        for(i=0;i<n-1;i++)
        {
            if(judge(s1,0,s2,0,i)&&judge(s1,i+1,s2,i+1,n-i-2) || judge(s1,0,s2,n-i-1,i)&&judge(s1,i+1,s2,0,n-i-2)) return true;
        }
        return false;
        
    }
};
int main()
{
	Solution a;
	string s1 = "abc";
	string s2 = "acb";
	if(a.isScramble(s1,s2)) printf("yes\n");
	else printf("no\n");
}