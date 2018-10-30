#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
class Solution 
{
public:
    int myAtoi(string str) 
	{
        string s;
		int i = 0;
		while(str[i]==' ' && i<str.size()) i++;
		if(i==str.size()) return 0;
		if( !(str[i]=='+' || str[i]=='-' || str[i]>='0'&&str[i]<='9' )) return 0;
		int k;
		if(str[i]=='+' || str[i]=='-') 
		{
			s += str[i];
			i++;
		}
		while(str[i]=='0') i++;
		for(k=i;k<str.size();k++)
		{
			if(!(str[k]>='0'&&str[k]<='9') ) break;
			s += str[k];
		}
		if(s[0]=='+' || s[0]=='-')
		{
			if(s.size()>11)
			{
				if(s[0]=='+') return 2147483647;
				else return -2147483648;
			}
			_int64 res = 0;
			_int64 times = 1;
			for(i=s.size()-1;i>0;i--)
			{
				res += (s[i] - '0') * times;
				times *= 10;
			}
			if(s[0]=='+')
			{
				if(res>2147483647) return 2147483647;
				return res;
			}
			else 
			{
				if(res>2147483648) return -2147483648;
				return -res;
			}
		}
		else
		{
			if(s.size()>10) return 2147483647;
			_int64 res = 0;
			_int64 times = 1;
			for(i=s.size()-1;i>=0;i--)
			{
				res += (s[i] - '0') * times;
				times *= 10;
			}
			if(res>2147483647) return 2147483647;
			return res;
		}
    }
};
int main()
{
	Solution a;
	string str = "  -000000000000000000000001";
	int res = a.myAtoi(str);
	printf("%d\n",res);
}