#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    int ConnectLeftToRight(TreeLinkNode *most_right_left,TreeLinkNode *most_left_right,int cur_depth,int depth,bool &flag)
    {
        if(flag) return depth;
        if(!most_right_left||!most_left_right) return cur_depth - 1;
        if(cur_depth==depth)
        {
            most_right_left->next = most_left_right;
            flag = true;
            return depth;
        }
		TreeLinkNode *sub_l = most_right_left->right;
		TreeLinkNode *sub_r = most_left_right->left;
		int depth1 = ConnectLeftToRight(sub_l,sub_r,cur_depth+1,depth,flag);
		sub_r = most_left_right->right;
		int depth2 = ConnectLeftToRight(sub_l,sub_r,cur_depth+1,depth,flag);
		sub_l = most_right_left->left;
		sub_r = most_left_right->left;
		int depth3 = ConnectLeftToRight(sub_l,sub_r,cur_depth+1,depth,flag);
		sub_r = most_left_right->right;
		int depth4 = ConnectLeftToRight(sub_l,sub_r,cur_depth+1,depth,flag);
        return max(max(depth1,depth2),max(depth3,depth4));
    }
    void connect(TreeLinkNode *root) {
        if(!root) return ;
        if(!(root->left)&&!(root->right)) return ;
        connect(root->left);
        connect(root->right);
        if(root->left&&root->right)
        {
            TreeLinkNode *most_right_left = root->left;
            TreeLinkNode *most_left_right = root->right;
			int depth = 0;
            while(1)
            {
                bool flag = false;
                if(ConnectLeftToRight(most_right_left,most_left_right,0,depth,flag)<depth) break;
                depth++;
            }
        }
    }
};
int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	TreeLinkNode *x1 = new TreeLinkNode (2);
	TreeLinkNode *x2 = new TreeLinkNode (3);
	root->left = x1;
	root->right = x2;
	Solution a;
	a.connect(root);
}