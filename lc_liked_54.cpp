#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
class Solution 
{
public:
	vector<int> res;
	void dfs(int x,int y,int dirx,int diry,bool **used,vector<vector<int> >& matrix)
	{
		int nx = x + dirx;
		int ny = y + diry;
		if(!(nx>=0&&nx<matrix.size()&&ny>=0&&ny<matrix[0].size())||used[nx][ny])
		{
			if(dirx==-1)
			{
				int ty = y + 1;
				if(ty>=0&&ty<matrix[0].size()&&!used[x][ty]) 
				{
					res.push_back(matrix[x][ty]);
					used[x][ty] = true;
					dfs(x,ty,0,1,used,matrix);
				}
				else return ;
			}
			if(dirx==1)
			{
				int ty = y - 1;
				if(ty>=0&&ty<matrix[0].size()&&!used[x][ty]) 
				{
					res.push_back(matrix[x][ty]);
					used[x][ty] = true;
					dfs(x,ty,0,-1,used,matrix);
				}
				else return ;
			}
			if(diry==-1)
			{
				int tx = x - 1;
				if(tx>=0&&tx<matrix.size()&&!used[tx][y])
				{
					res.push_back(matrix[tx][y]);
					used[tx][y] = true;
					dfs(tx,y,-1,0,used,matrix);
				}
				else return ;
			}
			if(diry==1)
			{
				int tx = x + 1;
				if(tx>=0&&tx<matrix.size()&&!used[tx][y])
				{
					res.push_back(matrix[tx][y]);
					used[tx][y] = true;
					dfs(tx,y,1,0,used,matrix);
				}
				else return ;

			}
		}
		else
		{
			res.push_back(matrix[nx][ny]);
			used[nx][ny] = true;
			dfs(nx,ny,dirx,diry,used,matrix);
		}
	}
    vector<int> spiralOrder(vector<vector<int> >& matrix) 
	{
		res.clear();
		if(matrix.empty()) return res;
		bool **used = new bool*[matrix.size()];
		int i,j;
		for(i=0;i<matrix.size();i++)
		{
			used[i] = new bool[matrix[i].size()];
			for(j=0;j<matrix[i].size();j++) used[i][j] = false;
		}
		res.push_back(matrix[0][0]);
		used[0][0] = true;
        dfs(0,0,0,1,used,matrix);
		return res;
    }
};
int main()
{
	Solution a;
	vector<vector<int> > matrix;
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	tmp.push_back(4);
	tmp.push_back(5);
	tmp.push_back(6);
	tmp.push_back(7);
	tmp.push_back(8);
	tmp.push_back(9);
	tmp.push_back(10);
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(11);
	tmp.push_back(12);
	tmp.push_back(13);
	tmp.push_back(14);
	tmp.push_back(15);
	tmp.push_back(16);
	tmp.push_back(17);
	tmp.push_back(18);
	tmp.push_back(19);
	tmp.push_back(20);
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(7);
	tmp.push_back(8);
	tmp.push_back(9);
	//matrix.push_back(tmp);
	tmp.clear();
	vector<int> res = a.spiralOrder(matrix);
	int i;
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
}