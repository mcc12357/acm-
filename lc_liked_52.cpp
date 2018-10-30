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
    int res;
    void dfs(int x,int column,int cnt1,int cnt2,int n)
    {
        if(x==n-1)
        {
            res++;
            return;
        }
        int i;
        for(i=0;i<n;i++)//put current queen in column i
        {
            if( !((1<<i)&column) && !((1<<(x+1+i))&cnt1) && !((1<<(n-2-x+i))&cnt2) )
            {
                column |= (1<<i);
                cnt1 |= (1<<(x+1+i));
                cnt2 |= (1<<(n-2-x+i));
                dfs(x+1,column,cnt1,cnt2,n);
                column &= ~(1<<i);
                cnt1 &= ~(1<<(x+1+i));
                cnt2 &= ~(1<<(n-2-x+i));
            }
        }
    }
    int totalNQueens(int n) 
    {
        res = 0;
        int column = 0,cnt1 = 0,cnt2 = 0;
        int i;
        for(i=0;i<n;i++)
        {
            column |= (1<<i);
            cnt1 |= (1<<i);
            cnt2 |= (1<<(n-1+i));
            dfs(0,column,cnt1,cnt2,n);
            column &= ~(1<<i);
            cnt1 &= ~(1<<i);
            cnt2 &= ~(1<<(n-1+i));
        }
        return res;
    }
};
int main()
{
	Solution a;
	int res = a.totalNQueens(4);
	cout<<res<<endl;
}