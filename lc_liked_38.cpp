#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
class Solution 
{
public:
    string countAndSay(int n) 
    {
        int i;
        string a = "1";
		if(n==1) return a;
        string b;
        for(i=1;i<n;i++)
        {
            int j,k;
            b = "";
            for(j=0;j<a.size();j++)
            {
                k = j + 1;
                while(k<a.size()&&a[k]==a[j]) k++;
                b += (k-j+'0');
                b += a[j];
				j = k;
				j--;
            }
            a = b;
        }
        return b;
    }
};
int main()
{
	Solution a;
	string res = a.countAndSay(6);
	cout<<res<<endl;
}