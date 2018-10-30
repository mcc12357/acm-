#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<stack>
#include<vector>
stack<char> s;
class Solution 
{
public:
	vector<string> res;
	void generate(string tmp,char x,int num,int final)
	{
		tmp += x;
		if(x=='(')
		{
			s.push(x);
			if(num<final) 
			{
				generate(tmp,'(',num+1,final);
				//s.pop();
			}
			if(num<final) 
			{
				generate(tmp,')',num+1,final);
				//s.push('(');
			}
			s.pop();
		}
		else
		{
			if(s.empty()) return;
			s.pop();
			if(num==final)
			{
				if(s.empty())
				{
					res.push_back(tmp);
					s.push('(');
					return ;
				}
			}
			if(num<final) 
			{
				generate(tmp,'(',num+1,final);
				//s.pop();
			}
			if(num<final) 
			{
				generate(tmp,')',num+1,final);
				//s.push('(');
			}
			s.push('(');
		}
		tmp.erase(tmp.end()-1);
		return ;
	}
    vector<string> generateParenthesis(int n) 
	{
		res.clear();
		string tmp;
        generate(tmp,'(',1,2*n);
		return res;
    }
};
int main()
{
	Solution a;
	int n = 4;
	int i;
	vector<string> res = a.generateParenthesis(n);
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
}