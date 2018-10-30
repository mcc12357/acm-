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
    int numDistinct(string s, string t) {
        if(!s.size()||!t.size()) return 0;
		int i,j;
        //dp[i][j]  means current t[i] and s[j] total ways
        int **dp = new int*[t.size()];
        for(i=0;i<t.size();i++) dp[i] = new int[s.size()];
        //initialize
        if(s[0]==t[0]) dp[0][0] = 1;
		else dp[0][0] = 0;
        for(i=1;i<t.size();i++) 
        {
            dp[i][0] =  0;
        }
        for(i=1;i<s.size();i++)
        {
            if(s[i]==t[0]) dp[0][i] = dp[0][i-1] + 1;
            else dp[0][i] = dp[0][i-1];
        }
        for(i=1;i<t.size();i++)
        {
            for(j=1;j<s.size();j++)
            {
                if(t[i]==s[j]) dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[t.size()-1][s.size()-1];
    }
};
int main()
{
	string s = "b";
	string t = "a";
	Solution a;
	cout<<a.numDistinct(s,t)<<endl;
}