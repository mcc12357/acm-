#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
struct line
{
	int pos;
	int val;
};
bool cmp(line x,line y)
{
	return x.val<y.val;
}
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int abs(int x) 
{
	return x>=0?x:-x;
}
class Solution 
{
public:
    int maxArea(vector<int>& height) 
	{
        int n = height.size();
		line *l = new line[n];
		int i;
		for(i=0;i<n;i++) 
		{
			l[i].pos = i;
			l[i].val = height[i];
		}
		sort(l,l+n,cmp);
		bool *pMaxUsed = new bool[n];
		bool *pMinUsed = new bool[n];
		//bool pMaxUsed[100];
		//bool pMinUsed[100];
		//memset(pMaxUsed,0,n*sizeof(pMaxUsed));
		//memset(pMinUsed,0,n*sizeof(pMinUsed));

		/*
		千万记住，动态开数组最好不要用memset初始化，
		因为memset只能用于内存初始化，而动态开数组是在堆上开辟空间,运行会出错，原因暂时未知。
		*/

		for(i=0;i<n;i++) 
		{
			pMaxUsed[i] = false;
			pMinUsed[i] = false;
		}
		int pMax = n - 1,pMin = 0;
		pMaxUsed[n-1] = true;
		pMinUsed[0] = true;
		int res = 0;
		for(i=0;i<n-1;i++)
		{
			pMaxUsed[l[i].pos] = true;
			pMinUsed[l[i].pos] = true;
			if(l[i].pos==pMax)
			{
				while(pMax>=0 && pMaxUsed[pMax]) 
				{
					pMax--;
				}
			}
			if(l[i].pos==pMin)
			{
				while(pMin<n && pMinUsed[pMin]) pMin++;
			}
			int length = max(abs(l[i].pos-pMin),abs(pMax-l[i].pos));
			res = max(res,l[i].val*length);
		}
		delete [] pMaxUsed;
		delete [] pMinUsed;
		delete [] l;
		return res;
    }
};
int main()
{
	vector<int> height;
	height.push_back(14);
	height.push_back(0);
	height.push_back(12);
	height.push_back(3);
	height.push_back(8);
	height.push_back(3);
	height.push_back(13);
	height.push_back(5);
	height.push_back(14);
	height.push_back(8);
	Solution a;
	int res = a.maxArea(height);
	cout<<res<<endl;

	//memset初始化堆空间test
	/*
	int *a = new int[20];
	memset(a,0,20*sizeof(a));
	int i;
	for(i=0;i<20;i++) printf("%d\n",a[i]);
	*/
	
}