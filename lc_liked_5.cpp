#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
class Solution 
{
public:
    string longestPalindrome(string s) 
	{
        int i,j;
		string ss;
		int indexz = 0,indexs = 0;
		for(i=0;i<s.size()-1;i++)
		{
			ss += s[i];
			ss += '*';
		}
		ss += s[s.size()-1];
		int len = 1;
		int sslen = s.size() * 2 - 1;
		for(i=1;i<sslen-1;i++)
		{
			for(j=1;i-j>=0&&i+j<sslen;j++)
			{
				if(ss[i-j]!=ss[i+j]) break;
			}
			j--;
			int k,p=0;
			if(i%2) 
			{
				if(len<(j+1)/2*2) 
				{
					len = (j+1)/2*2;
					indexz = i;
					indexs = j;
				}
			}
			else 
			{
				if(len<j/2*2+1)
				{
					len = j / 2 * 2 + 1;
					indexz = i;
					indexs = j;
				}
			}
		}
		//res[len] = '\0';
		string res;
		int k;
		for(k=indexz-indexs;k<=indexz+indexs;k++) if(ss[k]!='*') res += ss[k];
		return res;
    }
};
int main()
{
	Solution a;
	string s = "aaacaca";
	string res = a.longestPalindrome(s);
	cout<<res<<endl;
	//printf("%s\n",res);
}