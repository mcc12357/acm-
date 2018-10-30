
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
	int max(int x,int y) {return x>y;}
	int min(int x,int y) {return x<y;}
    void FindMaxMinDepth(TreeNode* root,int cur_depth,int &max_depth,int &min_depth)
    {
        if(!(root->left) || !(root->right))
        {
            max_depth = max(max_depth,cur_depth);
            min_depth = min(min_depth,cur_depth);
        }
        if(root->left) FindMaxMinDepth(root->left,cur_depth+1,max_depth,min_depth);
        if(root->right) FindMaxMinDepth(root->right,cur_depth+1,max_depth,min_depth);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int max_depth = 0,min_depth = 0x7fffffff;
        FindMaxMinDepth(root,0,max_depth,min_depth);
        cout<<max_depth<<' '<<min_depth<<endl;
        if(max_depth-min_depth>1) return false;
        return true;
    }
};
int main()
{
	Solution a;
	TreeNode* root = new TreeNode(1);
	TreeNode* x1 = new TreeNode(2);
	TreeNode* x2 = new TreeNode(3);
	root->right = x1;
	x1->right = x2;
	if(a.isBalanced(root)) cout<<"yes"<<endl;
}