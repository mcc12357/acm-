#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int i;
		for(i=s.size()-1;i>=0;i--) if(s[i]!=' ') break;
		if(i==-1) return 0;
		int j;
		for(j=i;j>=0;j--) if(s[j]==' ') break;
		return i - j;
    }
};
int main()
{
	Solution a;
	string s = "ads sdf sdsdd";
	int res = a.lengthOfLastWord(s);
	cout<<res<<endl;
}