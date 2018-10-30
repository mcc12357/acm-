#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = 0;
        int j = 0;
        while(i<m&&j<n)
        {
            if(nums1[i]<nums2[j]) i++;
            else
            {
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
                nums1.pop_back();
            }
        }
        while(j<n)
        {
            nums1[m+j] = nums2[j];
            j++;
        }
    }
};
int main()
{
	Solution a;
	vector<>
}