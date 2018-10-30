#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
class Solution
{
    public:
    bool isMatch(string s,string p)
    {
        int i,j;
        if(s.size()==0&&p.size()==0) return true;
        if(s.size()==0)
        {
            for(i=0;i<p.size();i++) 
            {
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(p.size()==0) return false;
        int m = s.size();
        int n = p.size();
        
        //space complexity is O(m*n)
        /*bool **dp = new bool* [m+1];
        for(i=0;i<=m;i++) dp[i] = new bool[n+1];
        for(i=0;i<=m;i++)
            for(j=0;j<=n;j++)
            {
                dp[i][j] = false;//if first i in s and first j in p can match,current index is i-1 and j-1 
            }
        dp[0][0] = true;
        for(i=1;i<=n;i++)//be careful of boundary
        {
            if(p[i-1]=='*') dp[0][i] = true;
            else break;
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(p[j-1]!='*') dp[i][j] = dp[i-1][j-1] && (p[j-1]=='?'||p[j-1]==s[i-1]);
                else
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];*/
        
        //space complexity is O(n)
        bool **dp = new bool* [2];
        for(i=0;i<2;i++) dp[i] = new bool[n+1];
        for(i=0;i<2;i++)
            for(j=0;j<=n;j++) dp[i][j] = false;
        dp[0][0] = true;//here means s chooses nothing and p chooses nothing,these two are matched.
		//but since we use two arrays to store result,then next time dp[0][0] may represent s chooses 
		//first 2 letters and p chooses nothing.these two aren't matched.so we need to update dp[0][0] = false;
        for(i=1;i<=n;i++)
        {
            if(p[i-1]=='*') dp[0][i] = true;
            else break;
        }
        int k = 1;
        for(i=1;i<=m;i++)
        {
			if(i>1) dp[0][0] = false;//be very careful here!!! if we use two arrays to store result,which means dp[0][0] need to be changed after first iteration.
            for(j=1;j<=n;j++)
            {
                if(p[j-1]!='*') dp[k][j] = dp[k^1][j-1] && (p[j-1]=='?'||p[j-1]==s[i-1]);
                else
                {
                    dp[k][j] = dp[k^1][j] || dp[k][j-1];
                }
            }
            k ^= 1;
        }
        if(m&1) return dp[1][n];
        else return dp[0][n];
    }
};
int main()
{
	Solution a;
	string s = "bbbaab";
	string p = "a**?***";
	if(a.isMatch(s,p)) printf("yes\n");
	else printf("no\n");
}