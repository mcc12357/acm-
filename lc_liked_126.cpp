#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
class Solution {
public:
    vector<vector<string> > res;
    bool CanTranform(int x,int y,vector<string>& wordList)
    {
        int diff = 0;
		int i;
        for(i=0;i<wordList[x].size();i++)
        {
            if(wordList[x][i]!=wordList[y][i]) diff++;
            if(diff>1) return false;
        }
        return diff == 1;
    }
    void dfs(int x,vector<int> &ans,vector<int> par[],vector<string>& wordList)
    {
		int i;
        int n = wordList.size();
        if(x==n-1)
        {
            vector<string> s;
            for(int i=ans.size()-1;i>=0;i--)
            {
                s.push_back(wordList[ans[i]]);
            }
            res.push_back(s);
            return;
        }
        for(i=0;i<par[x].size();i++)
        {
            int cur = par[x][i];
            ans.push_back(cur);
            dfs(cur,ans,par,wordList);
            ans.pop_back();
        }
    }
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty()) return res;
		int i,j;
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()) return res;
        wordList.push_back(beginWord);//push beginWord into the wordList,index is n - 1 
        
        //build the graph
        int n = wordList.size();
        vector<int> g[n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j&&CanTranform(i,j,wordList)) 
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        bool *used = new bool[n];
        memset(used,false,sizeof(used));
        vector<int> par[n];
        queue<pair<int,int>> q;//first is index,second is length
        q.push(make_pair(n-1,0));
        int min_len = -1;
        while(!q.empty())
        {
            pair<int,int> tmp = q.front();
            q.pop();
            int x = tmp.first;
            int y = tmp.second;
            used[x] = true;
            if(wordList[x]==endWord)
            {
                min_len = y;
                continue;
            }
            if(min_len!=-1 && y>min_len) break;
            for(int i=0;i<g[x].size();i++)
            {
                int next = g[x][i];
                if(!used[next])
                {
                    q.push(make_pair(next,y+1));
                    par[next].push_back(x);
                }
            }
        }
        int end_index = find(wordList.begin(),wordList.end(),endWord) - wordList.begin();
        vector<int> ans;
        ans.push_back(end_index);
        //cout<<par[0][0]<<par[0][1]<<endl;
        dfs(end_index,ans,par,wordList);
        return res;
    }
};
int main()
{
	Solution a;
}