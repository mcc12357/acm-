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
		if(num==final && x==')' && s.empty())
		{
			res.push_back(tmp);
			return ;
		}
		if(num<final) 
		{
			tmp += '(';
			s.push('(');
			generate(tmp,'(',num+1,final);
			s.pop();
			tmp.erase(tmp.end()-1);

			if(!s.empty())
			{
				tmp += ')';
				s.pop();
				generate(tmp,')',num+1,final);
				s.push('(');
				tmp.erase(tmp.end()-1);
			}
		}
		return ;
	}
    vector<string> generateParenthesis(int n) 
	{
		res.clear();
		string tmp;
		while(!s.empty()) s.pop();
  		tmp += '(';
		s.push('(');
        generate(tmp,'(',1,2*n);
		return res;
    }
};
int main()
{
	Solution a;
	int n = 1;
	int i;
	vector<string> res = a.generateParenthesis(n);
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
}