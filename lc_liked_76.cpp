#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<unordered_map>
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        if(s.size()==0||t.size()==0) return "";
        unordered_map<char,int> dicT;
        unordered_map<char,int> dicS;
        //unordered_map<char,int>:: iterator it;
        int i,j;
        int totalT = t.size();
        for(i=0;i<t.size();i++)
        {
            if(dicT.find(t[i])==dicT.end()) 
            {
                dicT[t[i]] = 1;
            }
            else dicT[t[i]]++;
        }
        int ansl = 0,ansr = 0,anslen = s.size()+1;
        i = j = 0;
        int show = 0;
        while(i<s.size()&&j<s.size())
        {
            while(j<s.size()&&show<totalT)
            {
                if(dicT.find(s[j])!=dicT.end()) 
                {
                    if(dicS.find(s[j])==dicS.end()) 
                    {
                        dicS[s[j]] = 1;
                        show++;
                    }
                    else
                    {
                        dicS[s[j]]++;
                        if(dicS[s[j]]<=dicT[s[j]]) 
                        {
                            show++;
                        }
                    }
                }
                j++;
            }
            while(show==totalT)
            {
                dicS[s[i]]--;
                if(dicS[s[i]]<dicT[s[i]]) show--;
                i++;
            }
            if(j-i<anslen)
            {
                ansl = i - 1;
                ansr = j;
                anslen = j - (i - 1);
            }
        }
        if(anslen==s.size()+1) return "";
        return s.substr(ansl,ansr);
    }
};
int main()
{
	S
}