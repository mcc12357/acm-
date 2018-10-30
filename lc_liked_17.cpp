#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>
#include<vector>
//int k = 0;//如果要放在类里，不能直接赋初值，要写个函数初始化
class Solution 
{
public:
	vector<string> s;
	vector<string> res;
	int k;
	void init(){k=0;}
	void f(string a,int pos,char x,string digits,int size)
	{
		a += x;
		if(pos==size-1)
		{
			res.push_back(a);
			k++;
			return ;
		}
		int i;
		for(i=0;i<s[digits[pos+1]-'2'].size();i++)
		{
			f(a,pos+1,s[digits[pos+1]-'2'][i],digits,size);
		}
	}
    vector<string> letterCombinations(string digits) 
	{
		int i,j;
		s.clear();
		res.clear();
		init();
		if(digits.empty()) return res;
		for(i=0;i<=4;i++)
		{
			string tmp;
			tmp += ('a'+3*i);
			tmp += ('b'+3*i);
			tmp += ('c'+3*i);
			s.push_back(tmp);
		}
		string tmp7,tmp8,tmp9;
		tmp7 += "pqrs";
		tmp8 += "tuv";
		tmp9 += "wxyz";
		s.push_back(tmp7);
		s.push_back(tmp8);
		s.push_back(tmp9);
		for(i=0;i<s[digits[0]-'2'].size();i++)
		{
			string a;
			f(a,0,s[digits[0]-'2'][i],digits,digits.size());
		}
		return res;
    }
	
};
int main()
{
	Solution a;
	string digits = "7";
	vector<string> res = a.letterCombinations(digits);
	//cout<<k<<endl;
	int i;
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
	return 0;
}