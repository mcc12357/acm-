#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
//Solution 1 use stack to calculate
/*class Solution 
{
public:
	int max(int x,int y)
	{
		if(x>y) return x;
		return y;
	}
    int longestValidParentheses(string s) 
	{
		stack<int> sta;
		while(!sta.empty()) sta.pop();
		int i;
		sta.push(-1);
		int res = 0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='(')
			{
				sta.push(i);
			}
			else
			{ 
				sta.pop();
				if(sta.empty())
				{
					sta.push(i);
				}
				else
				{
					res = max(res,i-sta.top());
				}
			}
		}
		return res;
    }
};*/
//Solution 2 dp
class Solution 
{
public:
	int max(int x,int y)
	{
		if(x>y) return x;
		return y;
	}
    int longestValidParentheses(string s) 
	{
		int i;
		int *dp = new int[s.size()];
		for(i=0;i<s.size();i++) dp[i] = 0;
		int res = 0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]==')')
			{
				if(i>0&&s[i-1]=='(')
				{
					if(i==1) dp[i] = 2;
					else dp[i] = dp[i-2] + 2;
				}
				if(i>0&&s[i-1]==')')
				{
					if(i==dp[i-1]) continue;
					if(s[i-dp[i-1]-1]=='(') 
					{
						if(i==dp[i-1]-1) dp[i] = dp[i-1] + 2;
						dp[i] = dp[i-dp[i-1]-2] + dp[i-1] + 2;
					}
				}
			}
			res = max(res,dp[i]);
		}
		return res;
	}
};
int main()
{
	Solution a;
	string s = "()(())";
	int res = a.longestValidParentheses(s);
	cout<<res<<endl;
}