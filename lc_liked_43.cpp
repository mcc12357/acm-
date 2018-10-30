#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
class Solution 
{
public:
	int ctoi(char x)
	{
		return x - '0';
	}
	char itoc(int x)
	{
		return x + '0';
	}
	string plus(string s1,string s2)
	{
		int k = 0;
		string res;
		while(!res.empty()) res.erase(res.end()-1);
		int carry = 0;
		while(k<s1.size()&&k<s2.size())
		{
			int tmp = ctoi(s1[k]) + ctoi(s2[k]);
			tmp += carry;
			res += itoc(tmp%10);
			carry = tmp / 10;
			k++;
		}
		if(k<s2.size())
		{
			while(k<s2.size())
			{
				int tmp = ctoi(s2[k]) + carry;
				res += itoc(tmp%10);
				carry = tmp / 10;
				k++;
			}
			if(carry) res += itoc(carry);
		}
		else if(k<s1.size())
		{
			while(k<s1.size())
			{
				int tmp = ctoi(s1[k]) + carry;
				res += itoc(tmp%10);
				carry = tmp / 10;
				k++;
			}
			if(carry) res += itoc(carry);
		}
		else
		{
			if(carry) res += itoc(carry);
		}
		return res;
	}
	string cal(char x,string num)
	{
		int i;
		string res;
		while(!res.empty()) res.erase(res.end()-1);
		int carry = 0;
		for(i=num.size()-1;i>=0;i--)
		{
			int tmp = ctoi(x) * ctoi(num[i]);
			tmp += carry;
			res += itoc(tmp%10);
			carry = tmp / 10;
		}
		if(carry) res += itoc(carry);
		return res;
	}
    string multiply(string num1, string num2) 
	{
		int i,j;
		string last = "0";
		string current;
		for(i=num1.size()-1;i>=0;i--)
		{
			current = cal(num1[i],num2);
			int k = num1.size() - 1 - i;
			for(j=1;j<=k;j++) current.insert(current.begin(),'0');
			last = plus(last,current);
		}
		while(last[last.size()-1]=='0'&&last.size()>1) last.erase(last.end()-1);
		string res;
		for(i=last.size()-1;i>=0;i--) res += last[i];
		return res;
    }
};
int main()
{
	Solution a;
	string num1 = "45466";
	string num2 = "233";
	string res = a.multiply(num1,num2);
	cout<<res<<endl;
}