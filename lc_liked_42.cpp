#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int start = 0,end;
        while(start+1<height.size()&&height[start]<=height[start+1]) start++;
        if(start>=height.size()-1) return 0;
        end = start + 1;
        int res = 0;
        while(1)
        {
            int sum = 0;
            while(end<height.size()&&height[end]<height[start]) 
            {
                sum += height[end];
                end++;
            }
			if(end==height.size()) 
            {
				int h = min(height[start],height[end-1]);
				res += h * (end - start - 1) - sum;
                break;
            }
            int h = min(height[start],height[end]);
            res += h * (end - start - 1) - sum;
            start = end - 1;
            while(start+1<height.size()&&height[start]<=height[start]) start++;
            end = start + 1;
        }
        return res;
    }
};
int main()
{
	Solution a;
	vector<int> height(3);
	height[0] = 2;
	height[1] = 1;
	height[2] = 0;
	//height[3] = 2;
	//height[4] = 1;
	int res = a.trap(height);
	cout<<res<<endl;
}