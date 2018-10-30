#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
void init(int a[])
{
    int i;
    for(i=0;i<150;i++) a[i] = 0;
}
int max(int x,int y)
{
    if(x>y) return x;
    return y;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int currentlen = 1;
        int reslen = 1;
        int a[150];
        init(a);
        if(s.size()==1) return 1;
        int l = 0,r = 1;
        a[s[l]]++;
        while(l<s.size() && r<s.size())
        {
            while(a[s[r]]==0 && r<s.size())
            {
                a[s[r]]++;
                r++;
                currentlen++;
            }
            reslen = max(reslen,currentlen);
			a[s[r]]++;
			r++;
			currentlen++;
            if(r>=s.size()) break;
            while(a[s[r-1]]>1 && l<s.size())
            {
                a[s[l]]--;
                l++;
                currentlen--;
            }
        }
        return reslen;
    }
};
int main()
{
	Solution a;
	string s = "abcabcbb";
	int res = a.lengthOfLongestSubstring(s);
	printf("%d\n",res);
}