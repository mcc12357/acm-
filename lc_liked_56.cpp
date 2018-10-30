#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

//Definition for an interval.
struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool cmp(const Interval &x,const Interval &y)
	{
		if(x.start==y.start) return x.end<y.end;
		return x.start<y.start;
	}
class Solution 
{
public:
	int max(int x,int y) 
	{
		if(x>y) return x;
		return y;
	}
    vector<Interval> merge(vector<Interval>& intervals) 
	{
        sort(intervals.begin(),intervals.end(),cmp);
		int i,j;
		for(i=0;i<intervals.size();i++)
		{
			for(j=i+1;j<intervals.size();j++)
			{
				if(intervals[i].end<intervals[j].start) 
				{
					i = j;
					i--;
				}
				else
				{
					intervals[i].end = max(intervals[i].end,intervals[j].end);
					intervals.erase(intervals.begin()+j);
					j--;
				}
			}
		}
		return intervals;
    }
};
int main()
{

}