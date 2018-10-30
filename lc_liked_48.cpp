#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
class Solution 
{
public:
    void rotate(vector<vector<int> >& matrix) 
	{
		int m,n;
		if(matrix.size()%2)
		{
			m = matrix.size() / 2 + 1;
			n = matrix.size() / 2;
		}
        else
		{
			m = matrix.size() / 2;
			n = matrix.size() / 2;
		}
		int i,j,k;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				int tx[4],ty[4];
				tx[0] = i;
				ty[0] = j;
				for(k=1;k<=3;k++)
				{
					tx[k] = ty[k-1];
					ty[k] = matrix.size() - 1 - tx[k-1];
				}
				for(k=3;k>=1;k--) swap(matrix[tx[k]][ty[k]],matrix[tx[k-1]][ty[k-1]]);
			}
		}
		return ;
    }
};
int main()
{
	vector<vector<int> > matrix;
	vector<int> tmp;
	int i,j;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	tmp.push_back(4);
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(5);
	tmp.push_back(6);
	tmp.push_back(7);
	tmp.push_back(8);
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(9);
	tmp.push_back(10);
	tmp.push_back(11);
	tmp.push_back(12);
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(13);
	tmp.push_back(14);
	tmp.push_back(15);
	tmp.push_back(16);
	matrix.push_back(tmp);
	Solution a;
	a.rotate(matrix);
	for(i=0;i<matrix.size();i++)
	{
		for(j=0;j<matrix[i].size();j++) cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
}