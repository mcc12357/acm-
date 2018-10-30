#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
class Solution
{
public:
	queue<int> q;
	bool flag;
	void output(int root,int cur,int par,vector<int> &result,vector<vector<int> >& node)
	{
		if(flag) return ;
		int i;
		if(cur==root&&par!=-1)
		{
			flag = true;
			for(i=0;i<result.size()-1;i++)
			{
				cout<<result[i]<<endl;
			}
			return ;
		}
		for(i=0;i<node[cur].size();i++)
		{
			if(node[cur][i]==par) continue;
			result.push_back(node[cur][i]);
			output(root,node[cur][i],cur,result,node);
			result.pop_back();
		}
	}
	bool existCircle(vector<vector<int> >& node,int n)
	{
		bool *used = new bool[n];
		int *parent = new int[n];
		int i,j;
		for(i=0;i<n;i++) 
		{
			used[i] = false;
			parent[i] = -1;
		}
		for(i=0;i<n;i++)
		{
			if(!used[i])
			{
				int t = i;
				parent[t] = t;
				while(!q.empty()) q.pop();
				q.push(t);
				used[t] = true;
				while(!q.empty())
				{
					t = q.front();
					for(j=0;j<node[t].size();j++)
					{
						if(node[t][j]==parent[t]) continue;
						if(used[node[t][j]])
						{
							vector<int> result;
							result.clear();
							result.push_back(node[t][j]);
							flag = false;
							output(node[t][j],node[t][j],-1,result,node);
							return true;
						}
						parent[node[t][j]] = t;
						used[node[t][j]] = true;
					}
					q.pop();
				}
			}
		}
	}
};
int main()
{
	vector<vector<int> > node(8);
	node[0].push_back(2);
	node[1].push_back(2);
	node[2].push_back(0);
	node[2].push_back(1);
	node[2].push_back(3);
	node[2].push_back(4);
	node[3].push_back(2);
	node[3].push_back(5);
	node[4].push_back(2);
	node[4].push_back(5);
	node[5].push_back(3);
	node[5].push_back(4);
	node[5].push_back(6);
	node[5].push_back(7);
	node[6].push_back(5);
	node[7].push_back(5);
	Solution a;
	a.existCircle(node,8);
}

