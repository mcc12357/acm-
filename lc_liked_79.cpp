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
    bool flag;
    void dfs(int x,int y,int index,int k,int dirx[],int diry[],vector<vector<bool> > &used,vector<vector<char> >& board, string word)
    {
        if(flag) return ;
        int cx = x + dirx[k];
        int cy = y + diry[k];
        if(index==word.size()-1)
        {
            if(board[cx][cy]==word[index])
            {
                flag = true;
            }
            return ;
        }
        int i;
        for(i=0;i<4;i++)
        {
            int nx = cx + dirx[i];
            int ny = cy + diry[i];
            if(nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size()&&!used[nx][ny]&&board[nx][ny]==word[index+1])
            {
                used[nx][ny] = true;
                dfs(cx,cy,index+1,i,dirx,diry,used,board,word);
                used[nx][ny] = false;
            }
        }
    }
    bool exist(vector<vector<char> >& board, string word) 
    {
        flag = false;
        if(board.empty()) 
        {
            if(word.empty()) return true;
            else return false;
        }
        if(word.empty()) 
        {
            if(board[0].empty()) return true;
            return false;
        }
        vector<vector<bool> > used(board.size(),vector<bool> (board[0].size()));
        int dirx[] = {0,0,-1,1};
        int diry[] = {-1,1,0,0};
        int i,j,k;
        for(i=0;i<board.size();i++)
        {
            for(j=0;j<board[0].size();j++)
            {
                for(int ii=0;ii<board.size();ii++)
                {
                    for(int jj=0;jj<board[0].size();jj++) used[ii][jj] = false;
                }
                if(board[i][j]==word[0])
                {
                    for(k=0;k<4;k++)
                    {
                        used[i][j] = true;
                        dfs(i-dirx[k],j-diry[k],0,k,dirx,diry,used,board,word);
                        used[i][j] = false;
                        if(flag) return flag;
                    }
                }
            }
        }
        return flag;
    }
};
int main()
{
	vector<vector<char> > board(3,vector<char> (3));
	board[0][0] = 'a';
	board[0][1] = 'd';
	board[0][2] = 's';
	board[1][0] = 'c';
	board[1][1] = 's';
	board[1][2] = 'b';
	board[2][0] = 's';
	board[2][1] = 'h';
	board[2][2] = 'd';
	string word = "adsb";
	Solution a;
	if(a.exist(board,word)) cout<<"yes"<<endl;

}