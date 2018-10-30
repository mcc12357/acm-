#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
class Solution 
{
public:
    vector<vector<string> > res;
    int abs(int x)
    {
        return x>0?x:-x;
    }
    void dfs(int x,int y,vector<int> &vy,int n)
    {
        int i,j;
        if(x==n-1)
        {
            vector<string> tmp;
			tmp.clear();
            for(i=0;i<n;i++)
            {
                string s;
                for(j=0;j<n;j++) s += '.';
                s[vy[i]] = 'Q';
                tmp.push_back(s);
            }
            res.push_back(tmp);
            return;
        }
        for(j=0;j<n;j++)
        {
            bool flag = true;
            for(i=0;i<=x;i++)
            {
                if(vy[i]==j || abs(i-x-1) == abs(j-vy[i]) )
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                vy.push_back(j);
                dfs(x+1,j,vy,n);
				vy.pop_back();
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) 
    {
        int i;
        for(i=0;i<res.size();i++) res[i].clear();
        for(i=0;i<n;i++)
        {
            vector<int> vy;
            vy.clear();
            vy.push_back(i);
            dfs(0,i,vy,n);
			vy.pop_back();
        }
        return res;
    }
};
int main()
{
	Solution a;
	vector<vector<string> > res;
	res = a.solveNQueens(4);
	int i,j;
	for(i=0;i<res.size();i++) 
	{
		for(j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<endl;;
		}
	}
}

