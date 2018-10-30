#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
int max(int x,int y)
{
	return x>y?x:y;
}
class Solution 
{
public:
    int maximalRectangle(vector<vector<char> >& matrix) 
    {
        if(matrix.size()==0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int i,j;
        int ans = 0;
        int *h = new int[n];
        int *l = new int[n];
        int *r = new int[n];
        stack<int> s;
        for(i=0;i<n;i++) h[i] = 0;
        for(i=0;i<m;i++)
        {
            while(!s.empty()) s.pop();
            for(j=0;j<n;j++)
            {
                h[j] = (matrix[i][j]=='0'?0:h[j]+1);
                if(s.empty())
                {
                    l[j] = 0;
                    s.push(j);
                }
                else
                {
                    while(!s.empty()&&h[s.top()]>=h[j])
                    {
                        s.pop();
                    }
                    if(s.empty()) l[j] = j;
                    else l[j] = j - s.top() - 1;
                    s.push(j);
                }
            }
            while(!s.empty()) s.pop();
            for(j=n-1;j>=0;j--)
            {
                if(s.empty())
                {
                    r[j] = 0;
                    s.push(j);
                }
                else
                {
                    while(!s.empty()&&h[s.top()]>=h[j])
                    {
                        s.pop();
                    }
                    if(s.empty()) r[j] = n - j - 1;
                    else r[j] = s.top() - j - 1;
                    s.push(j);
                }
            }
            for(j=0;j<n;j++) 
            {
                ans = max(ans,h[j]*(l[j]+r[j]+1));
            }
        }
        return ans;
    }
};
int main()
{
	vector<vector<char> > matrix(4,vector<char> (5));
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			char x;
			cin>>x;
			matrix[i][j] = x;
		}
	}
	Solution a;
	int res = a.maximalRectangle(matrix);
	cout<<res<<endl;

}