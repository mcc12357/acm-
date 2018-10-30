#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
class Solution 
{
public:
    string convert(string s, int numRows) 
	{
		if(s.size()==0) return "";
		if(numRows==1) return s;
        int mod = 2 * (numRows - 1);
		string res;
		int i,j;
		int k = s.size() / mod;
		for(i=0;i<=mod/2;i++)
		{
			for(j=0;j<=k;j++)
			{
				if(i==0 || i==mod/2)
				{
					int index = j * mod + i;
					if(index<s.size()) res += s[index];
				}
				else
				{
					int index = j * mod + i;
					if(index<s.size()) res += s[index];
					index = (j + 1)* mod - i;
					if(index<s.size()) res += s[index];
				}
			}
		}
		return res;
    }
};
int main()
{
	Solution a;
	string s = "";
	string res = a.convert(s,3);
	cout<<res<<endl;
}