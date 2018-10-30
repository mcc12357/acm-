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
    int line[9],row[9],grid[9];
    int n;
    bool find;
    void update(int x,int y,int k,vector<vector<char> >& board)
    {
        board[x][y] = k + 1 + '0';
        line[x] |= (1<<k);
        row[y] |= (1<<k);
        grid[x/3*3+y/3] |= (1<<k);
    }
    void back(int x,int y,int k,vector<vector<char> >& board)
    {
        board[x][y] = '.';
        line[x] &= ~(1<<k);
        row[y] &= ~(1<<k);
        grid[x/3*3+y/3] &= ~(1<<k);
    }
    void dfs(int x,int y,vector<vector<char> >& board)
    {
        int i;
        if(find) return;
        int nx,ny;
        if(y==n-1)
        {
            if(x==n-1)
            {
                find = true;
                return ;
            }
            else 
            {
                nx = x + 1;
                ny = 0;
            }
        }
        else
        {
            nx = x;
            ny = y + 1;
        }
        if(board[nx][ny]!='.') dfs(nx,ny,board);
        else
        {
            for(i=0;i<9;i++)
            {
                if(((1<<i)&line[nx])==0&&((1<<i)&row[ny])==0&&((1<<i)&grid[nx/3*3+ny/3])==0)
                {
                    update(nx,ny,i,board);
                    dfs(nx,ny,board);
                    if(find) return ;
                    back(nx,ny,i,board);
                }
            }
        }
    }
    void solveSudoku(vector<vector<char> >& board) 
    {
        memset(line,0,sizeof(line));
        memset(row,0,sizeof(row));
        memset(grid,0,sizeof(grid));
        n = 9;
        find = false;
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]!='.') update(i,j,board[i][j]-'0'-1,board);
            }
        }
        if(board[0][0]=='.')
        {
            for(i=0;i<9;i++)
            {
                if(((1<<i)&line[0])==0&&((1<<i)&row[0])==0&&((1<<i)&grid[0])==0)
                {
                    update(0,0,i,board);
                    dfs(0,0,board);
                    if(find) return ;
                    back(0,0,i,board);
                }
            }
        }
        else dfs(0,0,board);
    }
};
int main()
{
	Solution a;
	vector<vector<char> > board(9,vector<char> (9));
	int i,j;
	for(i=0;i<9;i++) for(j=0;j<9;j++) cin>>board[i][j];
	a.solveSudoku(board);
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
}