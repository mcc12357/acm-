#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
class Solution 
{
public:
    bool isValidSudoku(vector<vector<char> >& board) 
	{
        int i,j;
		bool used[10];
		int n = 9;

		//�������
		for(i=0;i<n;i++)
		{
			memset(used,0,sizeof(used));
			for(j=0;j<n;j++)
			{
				if(board[i][j]=='.') continue;
				if(used[board[i][j]-'0']) return false;
				used[board[i][j]-'0'] = true;
			}
		}
		//��������
		for(i=0;i<n;i++)
		{
			memset(used,0,sizeof(used));
			for(j=0;j<n;j++)
			{
				if(board[j][i]=='.') continue;
				if(used[board[j][i]-'0']) return false;
				used[board[j][i]-'0'] = true;
			}
		}
		//����Ź���
		int m = n / 3;
		int k,p;
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				memset(used,0,sizeof(used));
				int x = i * 3;
				int y = j * 3;
				for(k=0;k<m;k++)
				{
					for(p=0;p<m;p++)
					{
						int posx = x + k;
						int posy = y + p;
						if(board[posx][posy]=='.') continue;
						if(used[board[posx][posy]-'0']) return false;
						used[board[posx][posy]-'0'] = true;
					}
				}
			}
		}
		return true;
    }
};